/*
 * Problem 3129: Find All Possible Stable Binary Arrays I (POTD)
 * Language: C++
 */
class Solution {
    int dp[205][205][3];
    const int mod = 1e9 + 7;

    int solve(int z, int o, int prev, int lim) {
        if (z == 0 && o == 0) return 1;
        
        if (dp[z][o][prev] != -1) return dp[z][o][prev];

        long long ans = 0;
        if (prev != 0) {
            for (int k = 1; k <= min(z, lim); ++k) {
                ans = (ans + solve(z - k, o, 0, lim)) % mod;
            }
        }
        if (prev != 1) {
            for (int k = 1; k <= min(o, lim); ++k) {
                ans = (ans + solve(z, o - k, 1, lim)) % mod;
            }
        }

        return dp[z][o][prev] = ans;
    }

public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        return solve(zero, one, 2, limit); 
    }
};