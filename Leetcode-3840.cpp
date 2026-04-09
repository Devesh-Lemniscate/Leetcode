/*
 * Problem 3840: House Robber V
 * Language: C++
 */
class Solution {
public:
    long long helper(int i, vector<int>& nums, vector<int>& colors, vector<long long>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        long long nottake = helper(i + 1, nums, colors, dp);
        long long take = nums[i];
        if (i + 1 < nums.size() && colors[i] == colors[i + 1]) take += helper(i + 2, nums, colors, dp);
        else take += helper(i + 1, nums, colors, dp);
        return dp[i] = max(nottake, take);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long> dp(nums.size(), -1);
        return helper(0, nums, colors, dp);
    }
};