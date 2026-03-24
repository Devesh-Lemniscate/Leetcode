/*
 * Problem 2906: Construct Product Matrix (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));
        
        long long pref = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = pref;
                pref = (pref * grid[i][j]) % 12345;
            }
        }
        
        long long suff = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = (p[i][j] * suff) % 12345;
                suff = (suff * grid[i][j]) % 12345;
            }
        }
        
        return p;
    }
};