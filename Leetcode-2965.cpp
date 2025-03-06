class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            unordered_map<int, int> mp;
            int a, b;
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    mp[grid[i][j]]++;
                    if(mp[grid[i][j]]==2)a=grid[i][j];
                }
            }
            for(int i = 1; i <= grid.size()*grid.size(); i++){
                if(mp[i]==0){
                    b = i;
                    break;
                }
            }
            return {a,b};
        }
    };