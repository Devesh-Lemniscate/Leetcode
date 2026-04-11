/*
 * Problem 518: Coin Change II (POTD)
 * Language: C++
 */
class Solution {
public:
    int helper(int amt, int idx, vector<int>& coins, vector<vector<int>> &dp){
        if(amt==0) return 1;
        if(idx >= coins.size() || amt < 0) return 0;
        if(dp[idx][amt] != -1) return dp[idx][amt];
        
        int take = helper(amt - coins[idx], idx, coins, dp);
        int notTake = helper(amt, idx + 1, coins, dp);

        return dp[idx][amt] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        return helper(amount, 0, coins, dp);
    }
};