/*
 * Problem 3643: Flip Square Submatrix Vertically (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i = x;
        int j = x+k-1;
        while(i < j){
            for(int it = y; it < y+k; it++) swap(grid[i][it], grid[j][it]);
            i++;
            j--;
        }
        return grid;
    }
};