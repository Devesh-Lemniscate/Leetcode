/*
 * Problem 2395: Find Subarrays With Equal Sum
 * Language: C++
 */
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 1; i < nums.size(); i++) mp[nums[i]+nums[i-1]]++;
        for(auto it: mp) if(it.second > 1) return true;
        return false;
    }
};