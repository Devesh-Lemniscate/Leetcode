/*
 * Problem 3225: Maximum Score From Grid Operations (POTD)
 * Language: C++
 */
class Solution {
private:
    long long memo[105][105][105];
    long long max_left[105][105][105];
    long long max_right[105][105][105];
    bool vis[105][105];
    
    long long helper(int col, int h, int prev, vector<vector<long long>>& nums){
        int n = nums.size(), m = nums[0].size();
        if(col == m) return 0;
        if(memo[col][h][prev] != -1) return memo[col][h][prev];
        
        if(!vis[col][h]){
            vis[col][h] = true;
            long long lower = (h > 0) ? nums[h - 1][col] : 0;
            int end = (col == m - 1) ? 0 : n;
            
            vector<long long> next_vals(end + 1, 0);
            for(int i = 0; i <= end; i++){
                next_vals[i] = helper(col + 1, i, h, nums);
            }
            
            long long cur_max = -1;
            for(int p = 0; p <= n; p++){
                if(p <= end) cur_max = max(cur_max, next_vals[p]);
                long long s1_prev = (p > h) ? nums[p - 1][col] - lower : 0;
                max_left[col][h][p] = (cur_max != -1) ? (s1_prev + cur_max) : -1;
            }
            
            long long cur_right_max = -1;
            for(int p = n; p >= 0; p--){
                if(p <= end){
                    long long s1_p = (p > h) ? nums[p - 1][col] - lower : 0;
                    cur_right_max = max(cur_right_max, s1_p + next_vals[p]);
                }
                max_right[col][h][p] = cur_right_max;
            }
        }
        
        long long s2 = -1;
        if(max_left[col][h][prev] != -1){
            s2 = max(s2, max_left[col][h][prev]);
        }
        if(prev + 1 <= n && max_right[col][h][prev + 1] != -1){
            s2 = max(s2, max_right[col][h][prev + 1]);
        }
        
        return memo[col][h][prev] = s2;
    }
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> nums(n, vector<long long> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0) nums[i][j] = grid[i][j];
                else nums[i][j] = grid[i][j] + nums[i-1][j];
            }
        }
        
        memset(memo, -1, sizeof(memo));
        memset(vis, 0, sizeof(vis));
        long long ans = 0;
        
        for(int h = 0; h <= n; h++){
            ans = max(ans, helper(0, h, 0, nums));
        }
        
        return ans;
    }
};