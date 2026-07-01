/*
 * Problem 2812: Find the Safest Path in a Grid (POTD)
 * Language: C++
 */
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) q.push({i, j});
            }
        }
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0){
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        priority_queue<pair<int, pair<int, int>>> pq;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push({grid[0][0] - 1, {0, 0}});
        visited[0][0] = true;
        
        while(!pq.empty()){
            int safety = pq.top().first;
            int x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            
            if(x == n - 1 && y == n - 1) return safety;
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    
                    int next_safety = min(safety, grid[nx][ny] - 1);
                    pq.push({next_safety, {nx, ny}});
                }
            }
        }
        
        return 0;
    }
};