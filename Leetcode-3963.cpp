/*
 * Problem 3963: Create Grid With Exactly One Path (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(n, string(m, '#'));
        for (int i = 0; i < m; i++)
            grid[0][i] = '.';
        for (int i = 0; i < n; i++)
            grid[i][m - 1] = '.';
        return grid;
    }
};