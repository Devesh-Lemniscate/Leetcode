class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int, int>> q;
            int freshOranges = 0;
            int n = grid.size(), m = grid[0].size();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j]==1)freshOranges++;
                    else if(grid[i][j]==2)q.push({i,j});
                }
            }   
            if(!freshOranges) return 0;
            int minutes = -1;
            while(q.size()){
                int len = q.size();
                while(len--){
                    auto curr = q.front(); q.pop();
                    int row = curr.first, col = curr.second;
                    if(row-1>=0 && grid[row-1][col]==1){
                        grid[row-1][col] = 2;
                        freshOranges--;
                        q.push({row-1, col});
                    }
                    if(row+1<n && grid[row+1][col]==1){
                        grid[row+1][col] = 2;
                        freshOranges--;
                        q.push({row+1, col});
                    }
                    if(col-1>=0 && grid[row][col-1]==1){
                        grid[row][col-1] = 2;
                        freshOranges--;
                        q.push({row, col-1});
                    }
                    if(col+1<m && grid[row][col+1]==1){
                        grid[row][col+1] = 2;
                        freshOranges--;
                        q.push({row, col+1});
                    }
                }
                minutes++;
            }
            return freshOranges==0?minutes:-1;
        }
    };