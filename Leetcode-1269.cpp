/*
 * Problem 1269: Number of Ways to Stay in the Same Place After Some Steps
 * Language: C++
 */
class Solution {
private:
    const int mod = 1e9+7;
    int solve(int n, int steps, int place, vector<vector<int>> &dp){
        if(steps == 0) return place == 0;
        if(dp[steps][place] != -1) return dp[steps][place];
        int ans = 0;
        if(place + 1 < n) ans = (ans + solve(n, steps-1, place+1, dp)) % mod;
        if(place -1 >= 0) ans = (ans + solve(n, steps-1, place-1, dp)) % mod;
        ans = (ans + solve(n, steps-1, place, dp)) % mod;
        return dp[steps][place] = ans;
    }
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1, vector<int> (steps+1, -1));
        return solve(arrLen, steps, 0, dp);
    }
};