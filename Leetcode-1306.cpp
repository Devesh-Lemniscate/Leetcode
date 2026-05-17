/*
 * Problem 1306: Jump Game III (POTD)
 * Language: C++
 */
class Solution {
private:
    bool solve(int idx, vector<int> &nums, vector<int> &dp){
        if(idx < 0 || idx >= nums.size()) return false;
        if(nums[idx] == 0) return true;
        if(dp[idx] == 2) return false;
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = 2;
        return dp[idx] = solve(idx-nums[idx], nums, dp) || solve(idx+nums[idx], nums, dp);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size()+1, -1);
        return solve(start, arr, dp);
    }
};