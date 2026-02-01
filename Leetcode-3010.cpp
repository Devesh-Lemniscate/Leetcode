/*
 * Problem 3010: Divide an Array Into Subarrays With Minimum Cost I (POTD)
 * Language: C++
 */
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        nums[0] = INT_MAX;
        sort(nums.begin(), nums.end());
        return ans + nums[0] + nums[1];
    }
};