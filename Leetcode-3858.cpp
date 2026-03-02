/*
 * Problem 3858: Minimum Bitwise OR From Grid
 * Language: C++
 */
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            vector<vector<int>> val(n);
            bool check = true;
            for(int j = 0; j < n; j++){
                for(int k = 0; k < grid[j].size(); k++){
                    if(!(grid[j][k] & (1 << i))){
                        val[j].push_back(grid[j][k]);
                    }
                }
                if(!val[j].size()){
                    check = false;
                    break;
                }
            }
            if(!check) ans = ans | (1 << i);
            else grid = val;
        }
        return ans;
    }
};