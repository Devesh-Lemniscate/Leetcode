/*
 * Problem 1260: Shift 2D Grid (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = (i + ((j+k) / m)) % n;
                int y = (j + k % m) % m;
                res[x][y] = grid[i][j];
            }
        }
        return res;
    }
};