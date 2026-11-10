/*
 * Problem 3693: Climbing Stairs II (POTD)
 * Language: C++
 */
class Solution {
private:
    int n;
    int dp[100005];

    int helper(int i, vector<int> &costs){
        if(i == n) return 0;
        if(i > n) return 1e9;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        if(i+1 <= n) ans = min(ans, helper(i+1, costs) + costs[i] + 1);
        if(i+2 <= n) ans = min(ans, helper(i+2, costs) + costs[i+1] + 4);
        if(i+3 <= n) ans = min(ans, helper(i+3, costs) + costs[i+2] + 9);

        return dp[i] = ans;
    }
public:
    int climbStairs(int N, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        n = N;
        return helper(0, costs);
    }
};