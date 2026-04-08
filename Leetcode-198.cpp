/*
 * Problem 198: House Robber
 * Language: C++
 */
class Solution {
private:    
    int helper(int idx, vector<int> &nums, vector<int> &dp){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx] + helper(idx+2, nums, dp);
        int notTake = helper(idx+1, nums, dp);
        return dp[idx] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return helper(0, nums, dp);
    }
};