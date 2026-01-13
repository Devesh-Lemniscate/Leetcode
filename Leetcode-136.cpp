/*
 * Problem 136: Single Number
 * Language: C++
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto &it: nums) ans ^= it;
        return ans;
    }
};