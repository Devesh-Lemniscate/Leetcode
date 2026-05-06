/*
 * Problem 1861: Rotating the Box (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        for(int i = 0; i < n; i++){
            int j=0, count= 0;
            while(j < m){
                int k;
                for (k = j; k < m; k++) {
                    if (boxGrid[i][k] == '#') count++;
                    if (boxGrid[i][k] == '*') break;
                }
                for (int l = j; l < k; l++) boxGrid[i][l] = '.';
                for (int l = 1; l <= count; l++) boxGrid[i][k-l] = '#';
                j = k + 1;
                count = 0;
            }
        }
        vector<vector<char>> res(m, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j][n - 1 - i] = boxGrid[i][j];
            }
        }
        return res;
    }
};