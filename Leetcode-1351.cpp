/*
 * Problem 1351: Count Negative Numbers in a Sorted Matrix (POTD)
 * Language: C++
 */
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int i=m-1, j=0, count=0;
        while(i>=0 && i<m && j>=0 && j<n){
            if(grid[i][j] < 0){
                count = count + (n-j);
                i=i-1; 
            }
            else j=j+1;
        }       
        return count;
    }
};