/*
 * Problem 1582: Special Positions in a Binary Matrix (POTD)
 * Language: C++
 */
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bool vert = true, horiz = true;
                if(mat[i][j] == 1){
                    for(int k = 0; k < n; k++){
                        if(k != i  && mat[k][j]){
                            horiz = false;
                            break;
                        }
                    }
                    for(int k = 0; k < m; k++){
                        if(k != j  && mat[i][k]){
                            vert = false;
                            break;
                        }
                    }
                    if(horiz && vert) cnt++;
                }
            }
        }
        return cnt;
    }
};