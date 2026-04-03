/*
 * Problem 3661: Maximum Walls Destroyed by Robots (POTD)
 * Language: C++
 */
class Solution {
private:
    vector<vector<int>> dp;

    int helper(int idx, int next_dir, vector<pair<int, int>>& arr, vector<int>& walls) {
        if (idx < 0) return 0;
    
        if (dp[idx][next_dir] != -1) return dp[idx][next_dir];
        
        int n = arr.size();
        int left_bound = arr[idx].first - arr[idx].second;
        if (idx > 0) {
            left_bound = max(left_bound, arr[idx - 1].first + 1);
        }
        
        int l_idx = lower_bound(walls.begin(), walls.end(), left_bound) - walls.begin();
        int r_idx = lower_bound(walls.begin(), walls.end(), arr[idx].first + 1) - walls.begin();
        int walls_left = max(0, r_idx - l_idx);
        
        int ans_left = walls_left + helper(idx - 1, 0, arr, walls);
        
        int right_bound = arr[idx].first + arr[idx].second;
        if (idx + 1 < n) {
            if (next_dir == 0) { 
                right_bound = min(right_bound, arr[idx + 1].first - arr[idx + 1].second - 1);
            } else { 
                right_bound = min(right_bound, arr[idx + 1].first - 1);
            }
        }
        
        int l_idx2 = lower_bound(walls.begin(), walls.end(), arr[idx].first) - walls.begin();
        int r_idx2 = upper_bound(walls.begin(), walls.end(), right_bound) - walls.begin();
        int walls_right = max(0, r_idx2 - l_idx2);
        
        int ans_right = walls_right + helper(idx - 1, 1, arr, walls);
        
        return dp[idx][next_dir] = max(ans_left, ans_right);
    }

public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = {robots[i], distance[i]};
        }
        sort(arr.begin(), arr.end());
        sort(walls.begin(), walls.end());
        dp.assign(n, vector<int>(2, -1));
        return helper(n - 1, 1, arr, walls);
    }
};