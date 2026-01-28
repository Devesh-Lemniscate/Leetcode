/*
 * Problem 3651: Minimum Cost Path with Teleportations (POTD)
 * Language: C++
 */
class Solution {
const int INF = 1e9;
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INF));
        dp[0][0] = 0;

        vector<int> mini(10001); 

        for (int turn = 0; turn <= k; turn++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
                }
            }
            if (turn == k) break;
            fill(mini.begin(), mini.end(), INF);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int val = grid[i][j];
                    mini[val] = min(mini[val], dp[i][j]);
                }
            }
            for (int v = 9999; v >= 0; v--) mini[v] = min(mini[v], mini[v + 1]);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], mini[grid[i][j]]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};