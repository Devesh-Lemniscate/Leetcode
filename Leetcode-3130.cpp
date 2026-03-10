/*
 * Problem 3130: Find All Possible Stable Binary Arrays II (POTD)
 * Language: C++
 */
class Solution {
int dp[1001][1001][2];
const int mod = 1e9+7;
private:
    int solve(int z, int o, int prev, int lim){
        if(z == 0 && o == 0) return 0;
        if(z == 0) return (prev == 1 && o <= lim) ? 1 : 0;
        if(o == 0) return (prev == 0 && z <= lim) ? 1 : 0;
        if(dp[z][o][prev] != -1) return dp[z][o][prev];
        
        long long ans = 0;
        if (prev == 0) {
            ans = (solve(z - 1, o, 0, lim) + solve(z - 1, o, 1, lim)) % mod;
            if (z > lim) {
                ans = (ans - solve(z - lim - 1, o, 1, lim) + mod) % mod;
            }
        } else {
            ans = (solve(z, o - 1, 0, lim) + solve(z, o - 1, 1, lim)) % mod;
            if (o > lim) {
                ans = (ans - solve(z, o - lim - 1, 0, lim) + mod) % mod;
            }
        }
        return dp[z][o][prev] = ans;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        return (solve(zero, one, 0, limit) + solve(zero, one, 1, limit)) % mod;
    }
};