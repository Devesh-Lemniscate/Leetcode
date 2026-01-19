/*
 * Problem 1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size(), cols = mat[0].size();
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(row != 0) mat[row][col] += mat[row-1][col];
                if(col != 0) mat[row][col] += mat[row][col-1];
                if(row != 0 && col != 0) mat[row][col] -= mat[row-1][col-1];
            }
        }
        int maxi = 0;
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                int len = maxi + 1;
                if (row - len + 1 < 0 || col - len + 1 < 0) continue;
                int newRow = row - len; 
                int newCol = col - len;                
                int sum = mat[row][col];
                
                if (newRow >= 0) sum -= mat[newRow][col];
                if (newCol >= 0) sum -= mat[row][newCol];
                if (newRow >= 0 && newCol >= 0) sum += mat[newRow][newCol];

                if (sum <= threshold) maxi++;
            }
        }
        return maxi;
    }
};