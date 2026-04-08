/*
 * Problem 55: Jump Game
 * Language: C++
 */
class Solution {
private:
    bool helper(int idx, vector<int> &nums, vector<int> &dp){
        if(idx >= nums.size()) return false;
        if(idx == nums.size()-1) return true;
        if(dp[idx]!= -1) return dp[idx];
        bool ans = false;
        for(int i = 1; i <= nums[idx]; i++){
            ans |= helper(idx+i, nums, dp);
        }
        return dp[idx] = ans;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return helper(0, nums, dp);
    }
};