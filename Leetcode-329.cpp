/*
 * Problem 329: Longest Increasing Path in a Matrix
 * Language: C++
 */
class Solution {
private:
    int n, m;
    int dp[201][201][5];
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    int helper(int i, int j, int dir, vector<vector<int>> &nums){
        if(i < 0 || j < 0 || i == n || j == m) return 0;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        int ans = 1;
        for(int k = 0; k < 4; k++){
            if((dir == 0 && k == 1) || (dir == 1 && k == 0) || (dir == 2 && k == 3) || (dir == 3 && k ==2)) continue;
            int ni = i + dirX[k], nj = j + dirY[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && nums[ni][nj] > nums[i][j]){
                ans = max(ans, 1 + helper(ni, nj, k, nums));
            }
        }
        return dp[i][j][dir] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        int maxi = INT_MIN;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxi = max(maxi, helper(i, j, 4, matrix));
            }
        }
        return maxi;
    }
};