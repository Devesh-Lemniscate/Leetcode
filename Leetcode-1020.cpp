class Solution {
    public:
        void dfs(vector<vector<int>>& board, vector<vector<int>>& visited, int x, int y){
            int n = board.size(), m = board[0].size();
            visited[x][y] = 1;
            if(x-1>=0 && !visited[x-1][y] && board[x-1][y]==1) dfs(board, visited, x-1, y);
            if(x+1<n && !visited[x+1][y] && board[x+1][y]==1) dfs(board, visited, x+1, y);
            if(y-1>=0 && !visited[x][y-1] && board[x][y-1]==1) dfs(board, visited, x, y-1);
            if(y+1<m && !visited[x][y+1] && board[x][y+1]==1) dfs(board, visited, x, y+1);
    
        }
        int numEnclaves(vector<vector<int>>& board) {
            int n = board.size(), m = board[0].size();
            vector<vector<int>> visited(n, vector<int> (m, 0));
            for(int i = 0; i < n; i++){
                if(board[i][0]==1 && !visited[i][0]) dfs(board, visited, i, 0);
                if(board[i][m-1]==1 && !visited[i][m-1]) dfs(board, visited, i, m-1);
            }
            for(int i = 0; i < m; i++){
                if(board[0][i]==1 && !visited[0][i]) dfs(board, visited, 0, i);
                if(board[n-1][i]==1 && !visited[n-1][i]) dfs(board, visited, n-1, i);
            }
            int ans = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << visited[i][j]<< " ";
                    if(board[i][j]==1 && !visited[i][j]) ans++;
                }
                cout << endl;
            }
            return ans;
        }
    };