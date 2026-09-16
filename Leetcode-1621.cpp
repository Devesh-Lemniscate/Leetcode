/*
 * Problem 1621: Number of Sets of K Non-Overlapping Line Segments (POTD)
 * Language: C++
 */
class Solution {
private:
    const int mod = 1e9+7;
    int n, k;
    int dp[1001][1001][2];
    int helper(int ind, int count, bool flag){
        if(ind >= n) return 0;
        if(count == k) return 1;
        if(dp[ind][count][flag] != -1) return dp[ind][count][flag];
        int ans = 0;
        if(flag) ans = (ans % mod + helper(ind, (count+1) % mod, !flag) % mod) % mod;
        else ans = (ans % mod + helper(ind+1, count, !flag) % mod) % mod;
        return dp[ind][count][flag] = (ans%mod + helper(ind+1, count, flag) % mod) % mod;
    }
public:
    int numberOfSets(int num, int val) {
        n = num, k = val;
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, false);
    }
};