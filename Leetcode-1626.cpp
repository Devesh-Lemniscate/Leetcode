/*
 * Problem 1626: Best Team With No Conflicts
 * Language: C++
 */
class Solution {
private:
    int helper(int prev, int idx, vector<pair<int, int>> &nums, vector<vector<int>> &dp){
        if(idx >= nums.size()) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int take = 0;
        if(prev == -1 || nums[prev].second <= nums[idx].second) take = nums[idx].second + helper(idx, idx+1, nums, dp);
        int nottake = helper(prev, idx+1, nums, dp);
        return dp[idx][prev+1] = max(take, nottake);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> nums;
        for(int i = 0; i < scores.size(); i++){
            nums.push_back({ages[i], scores[i]});
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(scores.size(), vector<int> (scores.size()+1, -1));
        return helper(-1, 0, nums, dp);
    }
};