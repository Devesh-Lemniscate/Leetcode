class Solution {
    public:
        void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y){
            int n = board.size(), m = board[0].size();
            visited[x][y] = 1;
            if(x-1>=0 && !visited[x-1][y] && board[x-1][y]=='O') dfs(board, visited, x-1, y);
            if(x+1<n && !visited[x+1][y] && board[x+1][y]=='O') dfs(board, visited, x+1, y);
            if(y-1>=0 && !visited[x][y-1] && board[x][y-1]=='O') dfs(board, visited, x, y-1);
            if(y+1<m && !visited[x][y+1] && board[x][y+1]=='O') dfs(board, visited, x, y+1);
    
        }
        void solve(vector<vector<char>>& board) {
            int n = board.size(), m = board[0].size();
            vector<vector<int>> visited(n, vector<int> (m, 0));
            for(int i = 0; i < n; i++){
                if(board[i][0]=='O' && !visited[i][0]) dfs(board, visited, i, 0);
                if(board[i][m-1]=='O' && !visited[i][m-1]) dfs(board, visited, i, m-1);
            }
            for(int i = 0; i < m; i++){
                if(board[0][i]=='O' && !visited[0][i]) dfs(board, visited, 0, i);
                if(board[n-1][i]=='O' && !visited[n-1][i]) dfs(board, visited, n-1, i);
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << visited[i][j]<< " ";
                    if(board[i][j]=='O' && !visited[i][j]) board[i][j]='X';
                }
                cout << endl;
            }
        }
    };