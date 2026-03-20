/*
 * Problem 3567: Minimum Absolute Difference in Sliding Submatrix (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m= grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int> (m-k+1));
        for(int i = 0; i <n-k+1; i++){
            for(int j = 0; j < m-k+1; j++){
                vector<int> arr;
                for(int l = 0; l < k; l++){
                    for(int p = 0; p< k; p++){
                        arr.push_back(grid[i+l][j+p]);
                    }
                }
                sort(arr.begin(), arr.end());
                int mn = INT_MAX;
                for(int l = 1; l < arr.size(); l++){
                    if(arr[l]!=arr[l-1]) mn = min(mn, abs(arr[l]-arr[l-1]));
                }
                ans[i][j] = (mn==INT_MAX?0:mn);
            }
        }
        return ans;
    }
};