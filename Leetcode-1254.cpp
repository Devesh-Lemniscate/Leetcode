/*
 * Problem 1254: Number of Closed Islands (POTD)
 * Language: C++
 */
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<pair<int, int>> q;
        int ans = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = true;

                    bool closed = true;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        if (x == 0 || y == 0 ||
                            x == n - 1 || y == m - 1) {
                            closed = false;
                        }

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx >= 0 && nx < n &&
                                ny >= 0 && ny < m &&
                                !vis[nx][ny] &&
                                grid[nx][ny] == 0) {

                                q.push({nx, ny});
                                vis[nx][ny] = true;
                            }
                        }
                    }

                    if (closed) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};