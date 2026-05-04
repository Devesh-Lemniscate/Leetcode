/*
 * Problem 48: Rotate Image (POTD)
 * Language: C++
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i>=j) continue;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < m/2; i++){
            for(int j = 0; j < n; j++){
                swap(matrix[j][i], matrix[j][m-i-1]);
            }
        }
    }
};