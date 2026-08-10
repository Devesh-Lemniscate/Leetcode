/*
 * Problem 464: Can I Win
 * Language: C++
 */
class Solution {
private:
    bool solve(int mask, int total, int maxi, vector<int> &dp){
        if(dp[mask] != -1) return dp[mask];
        for(int i = 1; i <= maxi; i++){
            int bit = 1 << (i-1);
            if((mask & bit) == 0){
                if(i >= total || !solve(mask | bit, total-i, maxi, dp)){
                    return dp[mask] = 1;
                }
            }
        }
        return dp[mask] = 0;
    }
public:
    bool canIWin(int maxi, int total) {
        if(total == 0) return true;
        if(maxi * (maxi + 1) / 2 < total) return false;
        if(total <= maxi) return true;
        vector<int> dp(1 << maxi, -1);
        return solve(0, total, maxi, dp);
    }
};