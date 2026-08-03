/*
 * Problem 1406: Stone Game III (POTD)
 * Language: C++
 */
class Solution {
int dp[50005];
private:
    int helper(int ind, vector<int>& nums){
        int n = nums.size();
        if(ind >= n) return 0;
        if(dp[ind] != 1000000000) return dp[ind];
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        if(ind < n) first = nums[ind] - helper(ind+1, nums);
        if(ind + 1 < n) second = nums[ind] + nums[ind+1] - helper(ind + 2, nums);
        if(ind + 2 < n) third = nums[ind] + nums[ind+1] + nums[ind+2] - helper(ind + 3, nums);
        return dp[ind] = max(first, max(second, third));
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        for(int i = 0; i < stoneValue.size(); i++) dp[i] = 1e9;    
        int ans = helper(0, stoneValue);
        if(ans < 0) return "Bob";
        else if(ans > 0) return "Alice";
        else return "Tie";
    }
};