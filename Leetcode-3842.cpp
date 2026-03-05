/*
 * Problem 3842: Toggle Light Bulbs
 * Language: C++
 */
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int, int> mp;
        for(auto it: bulbs) mp[it]++;
        vector<int> ans;
        for(auto it: bulbs){
            if(!(mp[it] & 1)) continue;
            mp[it]--;
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};