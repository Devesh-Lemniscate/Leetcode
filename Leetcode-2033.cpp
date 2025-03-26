class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> ans;
            int n = grid.size(), m = grid[0].size();
            for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ans.push_back(grid[i][j]);
            sort(ans.begin(), ans.end());
            int target = ans[(n*m)/2], res = 0;
            for(int i = 0; i < n*m; i++){
                if(abs(ans[i]-target)%x!=0)return -1;
                else res+=abs(ans[i]-target)/x;
            }
            return res;
        }
    };