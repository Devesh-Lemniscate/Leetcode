class Solution {
    public:
        vector<vector<int>> helper(vector<vector<int>> &v){
            if(v.size() <= 1) return v;
            sort(v.begin(), v.end());
            vector<vector<int>> ans;
            ans.push_back(v[0]);
            for(int i = 1; i < v.size(); i++){
                if(v[i][0] < v[i-1][1]) v[i][1] = max(v[i][1], v[i-1][1]); 
                else ans.push_back(v[i]);
            }
            return ans;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>> a, b;
            for(auto v: rectangles){
                a.push_back({v[0], v[2]});
                b.push_back({v[1], v[3]});
            }
            a = helper(a);
            b = helper(b);
            return a.size()>=3 || b.size()>=3;
        }
    };