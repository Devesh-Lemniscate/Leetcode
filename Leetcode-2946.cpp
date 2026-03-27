/*
 * Problem 2946: Matrix Similarity After Cyclic Shifts (POTD)
 * Language: C++
 */
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        k = k % m;
        if (k % m == 0) return true;
        vector<vector<int>> nums(n, vector<int> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i & 1){
                    nums[i][j] = mat[i][(j+k) % m];
                }else{
                    nums[i][j] = mat[i][(j-k+m)%m];
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(nums[i][j] != mat[i][j]) return false;
            }
        }
        return true;
    }
};