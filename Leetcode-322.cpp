/*
 * Problem 322: Coin Change
 * Language: C++
 */
class Solution {
private:
    int helper(int idx, int amt, vector<int> & coins, vector<vector<int>> &dp){
        if(idx >= coins.size() || amt < 0) return 1e9;
        if(amt == 0) return 0;
        if(dp[idx][amt] != -1) return dp[idx][amt];
        int remain = 1 + helper(idx, amt-coins[idx], coins, dp);
        int move = 1 + helper(idx+1, amt-coins[idx], coins, dp);
        int notTake = helper(idx+1, amt, coins, dp);
        return dp[idx][amt] = min({remain, move, notTake});
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = helper(0, amount, coins, dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};