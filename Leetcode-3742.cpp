/*
 * Problem 3742: Maximum Path Score in a Grid (POTD)
 * Language: C++
 */
class Solution {
    int dp[201][201][201];
private:
    int helper(int i, int j, int sum, vector<vector<int>> &grid, int &k){
        int n = grid.size(), m = grid[0].size();
        if(i == n || j == m) return -1e9;
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        int cost = 0;
        if(grid[i][j] == 1 || grid[i][j]==2) cost = 1;
        if(sum+cost > k) return -1e9;
        
        if(i == n-1 && j == m-1) return grid[i][j];
        return dp[i][j][sum] = grid[i][j]+max(helper(i+1, j, sum+cost, grid, k), helper(i, j+1, sum+cost, grid, k));
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        memset(dp, -1, sizeof(dp));
        int ans = helper(0, 0, 0, grid, k);
        if(ans < 0) return -1;
        return ans;
    }
};