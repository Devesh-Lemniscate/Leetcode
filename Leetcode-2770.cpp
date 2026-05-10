/*
 * Problem 2770: Maximum Number of Jumps to Reach the Last Index (POTD)
 * Language: C++
 */
class Solution {
private:
    int solve(int idx, vector<int> &nums, int prev, int &target, vector<vector<int>>&dp){
        if(idx == nums.size()-1){
            if(prev == -1) return INT_MIN;
            else if(abs(nums[idx]-nums[prev]) > target) return INT_MIN;
            else return 1;
        }
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        
        int notTake = INT_MIN;
        if(prev != -1) {
            notTake = solve(idx+1, nums, prev, target, dp);
        }
        
        int take = INT_MIN;
        if(prev == -1) {
            take  = solve(idx+1, nums, idx, target, dp);
        } else if(abs(nums[idx]-nums[prev]) <= target) {
            int temp = solve(idx+1, nums, idx, target, dp);
            if (temp != INT_MIN) {
                take = 1 + temp;
            }
        }
        
        return dp[idx][prev+1] = max(take, notTake);
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, -1));
        int ans = solve(0, nums, -1, target, dp);
        return ans<=0?-1:ans;
    }
};