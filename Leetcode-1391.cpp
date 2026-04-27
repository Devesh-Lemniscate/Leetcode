/*
 * Problem 1391: Check if There is a Valid Path in a Grid (POTD)
 * Language: C++
 */
class Solution {
private:
    bool dfs(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &visited){
        if(n==0 && m==0) return true;
        if(n < 0 || m < 0 || n >= grid.size() || m >= grid[0].size()) return false;
        visited[n][m] = 1;
        
        if(grid[n][m] == 1) {
            if(m-1 >= 0 && !visited[n][m-1] && (grid[n][m-1] == 1 || grid[n][m-1] == 4 || grid[n][m-1]==6)) if(dfs(n, m-1, grid, visited)) return true;
            if(m+1 < grid[0].size() && !visited[n][m+1] && (grid[n][m+1] == 1 || grid[n][m+1] == 3 || grid[n][m+1]==5)) if(dfs(n, m+1, grid, visited)) return true;
        }else if(grid[n][m] == 2){ 
            if(n-1 >= 0 && !visited[n-1][m] && (grid[n-1][m] == 2 || grid[n-1][m] == 3 || grid[n-1][m]==4)) if(dfs(n-1, m, grid, visited)) return true;
            if(n+1 < grid.size() && !visited[n+1][m] && (grid[n+1][m] == 2 || grid[n+1][m] == 5 || grid[n+1][m]==6)) if(dfs(n+1, m, grid, visited)) return true;
        }else if(grid[n][m] == 3){ 
            if(m-1 >= 0 && !visited[n][m-1] && (grid[n][m-1] == 1 || grid[n][m-1] == 4 || grid[n][m-1]==6)) if(dfs(n, m-1, grid, visited)) return true;
            if(n+1 < grid.size() && !visited[n+1][m] && (grid[n+1][m] == 2 || grid[n+1][m] == 5 || grid[n+1][m]==6)) if(dfs(n+1, m, grid, visited)) return true;
        }else if(grid[n][m] == 4){ 
            if(m+1 < grid[0].size() && !visited[n][m+1] && (grid[n][m+1] == 1 || grid[n][m+1] == 3 || grid[n][m+1]==5)) if(dfs(n, m+1, grid, visited)) return true;
            if(n+1 < grid.size() && !visited[n+1][m] && (grid[n+1][m] == 2 || grid[n+1][m] == 5 || grid[n+1][m]==6)) if(dfs(n+1, m, grid, visited)) return true;
        }else if(grid[n][m] == 5){ 
            if(m-1 >= 0 && !visited[n][m-1] && (grid[n][m-1] == 1 || grid[n][m-1] == 4 || grid[n][m-1]==6)) if(dfs(n, m-1, grid, visited)) return true;
            if(n-1 >= 0 && !visited[n-1][m] && (grid[n-1][m] == 2 || grid[n-1][m] == 3 || grid[n-1][m]==4)) if(dfs(n-1, m, grid, visited)) return true;
        }else if(grid[n][m] == 6){ 
            if(m+1 < grid[0].size() && !visited[n][m+1] && (grid[n][m+1] == 1 || grid[n][m+1] == 3 || grid[n][m+1]==5)) if(dfs(n, m+1, grid, visited)) return true;
            if(n-1 >= 0 && !visited[n-1][m] && (grid[n-1][m] == 2 || grid[n-1][m] == 3 || grid[n-1][m]==4)) if(dfs(n-1, m, grid, visited)) return true;
        }
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size()-1, m = grid[0].size()-1;
        vector<vector<int>> visited(n+1, vector<int> (m+1, 0));
        return dfs(n, m, grid, visited);
    }
};