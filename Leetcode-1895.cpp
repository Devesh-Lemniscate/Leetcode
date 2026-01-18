/*
 * Problem 1895: Largest Magic Square (POTD)
 * Language: C++
 */
class Solution {
private:
    bool check(int r, int c, int k, vector<vector<int>>& grid, 
               vector<vector<int>>& rowPref, vector<vector<int>>& colPref) {
        
        int target = rowPref[r][c + k] - rowPref[r][c];
        for (int i = r + 1; i < r + k; i++)
            if (rowPref[i][c + k] - rowPref[i][c] != target) 
                return false;
        
        for (int j = c; j < c + k; j++)
            if (colPref[j][r + k] - colPref[j][r] != target) 
                return false;
        
        int diagonal1 = 0;
        for (int i = 0; i < k; i++) 
            diagonal1 += grid[r + i][c + i];
        if (diagonal1 != target) 
            return false;
        int diagonal2 = 0;
        for (int i = 0; i < k; i++) 
            diagonal2 += grid[r + i][c + k - 1 - i];
        if (diagonal2 != target) 
            return false;

        return true;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> rowPref(rows, vector<int>(cols + 1, 0));
        vector<vector<int>> colPref(cols, vector<int>(rows + 1, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                rowPref[row][col + 1] = rowPref[row][col] + grid[row][col];
                colPref[col][row + 1] = colPref[col][row] + grid[row][col];
            }
        }
        for (int sideLen = min(rows, cols); sideLen > 1; sideLen--) {
            for (int row = 0; row <= rows - sideLen; row++) {
                for (int col = 0; col <= cols - sideLen; col++) {
                    if (check(row, col, sideLen, grid, rowPref, colPref)) {
                        return sideLen;
                    }
                }
            }
        }
        return 1;
    }
};