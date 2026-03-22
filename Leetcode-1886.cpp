/*
 * Problem 1886: Determine Whether Matrix Can Be Obtained By Rotation (POTD)
 * Language: C++
 */
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int ans[4] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(target[i][j] == mat[n-j-1][i]) ans[0]++;
                if(target[i][j] == mat[n-i-1][n-j-1]) ans[1]++;
                if(target[i][j] == mat[j][n-i-1]) ans[2]++;
                if(target[i][j] == mat[i][j]) ans[3]++;
            }
        }
        int total = n*n;
        return (ans[0] == total || ans[1] == total || ans[2] == total || ans[3] == total);
    }
};