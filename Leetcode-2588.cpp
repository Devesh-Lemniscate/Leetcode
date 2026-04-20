/*
 * Problem 2588: Count the Number of Beautiful Subarrays
 * Language: C++
 */
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, int> mp; mp[0]=1;
        int num  = 0;
        for(auto it: nums){
            num ^= it;
            if(mp.find(num) != mp.end()) ans += mp[num];
            mp[num]++;
        }
        return ans ;
    }
};