class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            vector<vector<int>> vis(n, vector<int>(m, 0));
            vector<vector<int>> dis(n, vector<int>(m, 0));
            queue<pair<pair<int, int>, int>> q;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j]==0){
                        q.push({{i,j}, 0});
                        vis[i][j]=1;
                    }
                }
            }
            int x[] = {0,-1,0,1};
            int y[] = {1,0,-1,0};
            while(q.size()){
                int row = q.front().first.first, col = q.front().first.second;
                int step = q.front().second; q.pop();
                dis[row][col] = step;
    
                for(int i = 0; i < 4; i++){
                    int newRow = row+x[i];
                    int newCol = col+y[i];
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && vis[newRow][newCol]==0){
                        vis[newRow][newCol]=1;
                        q.push({{newRow, newCol}, step+1});
                    }
                }
            }
            return dis;
        }
    };