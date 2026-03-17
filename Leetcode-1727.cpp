/*
 * Problem 1727: Largest Submatrix With Rearrangements (POTD)
 * Language: C++
 */
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum = 0;
            for(int i = 0; i < n; i++){
                if(matrix[i][j] == 0) sum = 0;
                else sum += matrix[i][j];
                matrix[i][j] = sum;
            }
        }

        for(auto &it: matrix) sort(it.begin(), it.end());
        int maxi = 0;
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxi = max(maxi, matrix[i][j] * (m-j));
            } 
        }
        return maxi;
    }
};