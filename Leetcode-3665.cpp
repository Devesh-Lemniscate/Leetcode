/*
 * Problem 3665: Twisted Mirror Path Count (POTD)
 * Language: C++
 */
class Solution {
private:
    int dp[501][501][2];
    const int mod = 1e9+7;
    int n, m;
    int helper(int i, int j, vector<vector<int>>& grid, int dir){
        if(i == n-1 && j == m-1) return 1;
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        long long ans = 0;
        if(grid[i][j]){
            if(dir == 0){
                ans = (ans + helper(i+1, j, grid, 1)) % mod;
            }else{
                ans = (ans + helper(i, j+1, grid, 0)) % mod;
            }
        }else{
                ans = (ans + helper(i+1, j, grid, 1)) % mod;
                ans = (ans + helper(i, j+1, grid, 0)) % mod;
        }
        return dp[i][j][dir] = ans;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        n = grid.size(), m = grid[0].size();
        return helper(0, 0, grid, 0);
    }
};