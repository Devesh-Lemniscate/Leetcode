/*
 * Problem 3619: Count Islands With Total Value Divisible by K (POTD)
 * Language: C++
 */
class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int x, int y, long long &sum){
        int dx[]  = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        int n = grid.size(), m = grid[0].size();
        vis[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny]){
                sum += grid[nx][ny];
                dfs(grid, vis, nx, ny, sum);
            }
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !vis[i][j]){
                    long long sum = grid[i][j];
                    dfs(grid, vis, i, j, sum);
                    if(sum % k == 0) count++; 
                }
            }
        }
        return count;
    }
};