/*
 * Problem 3286: Find a Safe Walk Through a Grid (POTD)
 * Language: C++
 */
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        deque<pair<int, pair<int, int>>> dq;
        int n = grid.size(), m = grid[0].size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        dq.push_front({health,{0,0}});
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        visited[0][0] = true;
        while(!dq.empty()){
            int h = dq.front().first, x = dq.front().second.first, y = dq.front().second.second;
            dq.pop_front();
            if(grid[x][y]) h--;
            if(x == n-1 && y == m-1) return h > 0;

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    if(grid[nx][ny] == 0) dq.push_front({h, {nx, ny}});
                    else dq.push_back({h, {nx, ny}});
                }
            }
        }
        return 0;
    }
};