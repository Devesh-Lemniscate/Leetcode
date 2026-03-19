/*
 * Problem 3212: Count Submatrices With Equal Frequency of X and Y (POTD)
 * Language: C++
 */
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {0, 0}));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x_val = (grid[i][j] == 'X') ? 1 : 0;
                int y_val = (grid[i][j] == 'Y') ? 1 : 0;

                int prev_x = 0, prev_y = 0;
                
                if (i > 0) {
                    prev_x += dp[i-1][j].first;
                    prev_y += dp[i-1][j].second;
                }
                if (j > 0) {
                    prev_x += dp[i][j-1].first;
                    prev_y += dp[i][j-1].second;
                }
                if (i > 0 && j > 0) {
                    prev_x -= dp[i-1][j-1].first;
                    prev_y -= dp[i-1][j-1].second;
                }

                dp[i][j] = {prev_x + x_val, prev_y + y_val};

                if (dp[i][j].first == dp[i][j].second && dp[i][j].first > 0) cnt++;
            }
        }
        
        return cnt;
    }
};