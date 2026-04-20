/*
 * Problem 322: Coin Change
 * Language: C++
 */
class Solution {
public:
    long long helper(vector<int>& coins, vector<int> &dp, int amt){
        if(amt==0){
            return 0;
        }
        if(dp[amt]!=-1)return dp[amt];
        long long ans = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            if(amt-coins[i] < 0) continue;
            ans = min(ans, (helper(coins, dp, amt-coins[i])+1));
        }
        return dp[amt] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount ==0 )return 0;
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        helper(coins, dp, amount);
        
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};