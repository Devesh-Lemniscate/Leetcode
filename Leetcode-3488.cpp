/*
 * Problem 3488: Closest Equal Element Queries
 * Language: C++
 */
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(auto q: queries){
            auto& idx = mp[nums[q]];
            int s = idx.size();
            if(s < 2){
                ans.push_back(-1);
                continue;
            }
            int it = lower_bound(idx.begin(), idx.end(), q) - idx.begin();
            int dist1 = (q - idx[(it - 1 + s) % s] + n) % n;
            int dist2 = (idx[(it + 1) % s] - q + n) % n;
            ans.push_back(min(dist1, dist2));
        }
        return ans;
    }
};