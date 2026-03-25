/*
 * Problem 3546: Equal Sum Grid Partition I (POTD)
 * Language: C++
 */
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long nums[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                nums[i][j] = grid[i][j];
                if(i-1 >= 0) nums[i][j] += nums[i-1][j];
                if(j-1 >= 0) nums[i][j] += nums[i][j-1];
                if(i-1 >= 0 && j-1 >= 0) nums[i][j] -= nums[i-1][j-1];
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i][m-1] * 2 == nums[n-1][m-1]) return true;
        }
        for(int j = 0; j < m; j++){
            if(nums[n-1][j] * 2 == nums[n-1][m-1]) return true;
        }
        return false;
    }
};