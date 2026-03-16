/*
 * Problem 1878: Get Biggest Three Rhombus Sums in a Grid (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        set<int> sums; 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                sums.insert(grid[i][j]);

                for(int k = 1; i + 2 * k < n && j - k >= 0 && j + k < m; k++) {
                    int current_sum = 0;

                    for(int step = 0; step < k; step++) 
                        current_sum += grid[i + step][j + step];
                    
                    for(int step = 0; step < k; step++) 
                        current_sum += grid[i + k + step][j + k - step];
                    
                    for(int step = 0; step < k; step++) 
                        current_sum += grid[i + 2 * k - step][j - step];
                    
                    for(int step = 0; step < k; step++) 
                        current_sum += grid[i + k - step][j - k + step];

                    sums.insert(current_sum);
                }
            }
        }

        vector<int> ans;
        for (auto it = sums.rbegin(); it != sums.rend() && ans.size() < 3; it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};