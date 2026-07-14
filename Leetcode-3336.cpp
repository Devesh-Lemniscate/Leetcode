/*
 * Problem 3336: Find the Number of Subsequences With Equal GCD (POTD)
 * Language: C++
 */
class Solution {
private:
    int dp[201][201][201];
    int n, mod = 1e9+7;
    int solve(int idx, int x, int y, vector<int>&nums){
        if(idx == n) return (x != 0 && x == y);
        if(dp[idx][x][y] != -1) return dp[idx][x][y];
        dp[idx][x][y] = 0;
        dp[idx][x][y] = solve(idx+1, x, y, nums);
        int a = (x == 0) ? nums[idx] : __gcd(x, nums[idx]);
        dp[idx][x][y] = (dp[idx][x][y] + solve(idx+1, a, y, nums)) % mod;

        int b = (y == 0) ? nums[idx] : __gcd(y, nums[idx]);
        dp[idx][x][y] = (dp[idx][x][y] + solve(idx+1, x, b, nums)) % mod;

        return dp[idx][x][y];
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};