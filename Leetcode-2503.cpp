class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int n = grid.size(), m = grid[0].size();
            vector<int> res(queries.size());
            vector<vector<bool>> visited(n, vector<bool>(m, false));
    
            vector<pair<int, int>> qIdx;
            for (int i = 0; i < queries.size(); i++)
                qIdx.push_back({queries[i], i});
            
            sort(qIdx.begin(), qIdx.end()); 
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
            pq.push({grid[0][0], {0, 0}});
            visited[0][0] = true;
    
            int count = 0, maxThreshold = 0;
            vector<int> dirX = {1, 0, -1, 0};
            vector<int> dirY = {0, 1, 0, -1};
    
            for (auto &[query, idx] : qIdx) {
                while (!pq.empty() && pq.top().first < query) {
                    auto [val, pos] = pq.top(); pq.pop();
                    int x = pos.first, y = pos.second;
                    count++; 
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dirX[k], ny = y + dirY[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            pq.push({grid[nx][ny], {nx, ny}});
                        }
                    }
                }
                res[idx] = count; 
            }
    
            return res;
        }
    };
    