/*
 * Problem 1481: Least Number of Unique Integers after K Removals
 * Language: C++
 */
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto it: arr) mp[it]++;
        vector<pair<int, int>> nums;
        for(auto it: mp) nums.push_back({it.second, it.first});
        sort(nums.begin(), nums.end());
        int idx=0;
        while(idx < nums.size() && k >= nums[idx].first){
            k-=nums[idx].first;
            idx++;
        }
        return nums.size()-idx;
    }
};