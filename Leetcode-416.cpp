class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum & 1) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2 + 1, -1));
        return helper(nums, 0, sum/2, dp);
    }

private:
    bool helper(vector<int>& nums, int i, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (i >= nums.size() || sum < 0) return false;
        if (dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = helper(nums, i + 1, sum - nums[i], dp) || helper(nums, i + 1, sum, dp);
    }
};
