/*
 * Problem 1000: Minimum Cost to Merge Stones
 * Language: C++
 */
class Solution {
private:
    int solve(int i, int j, vector<int> &prefix, vector<vector<int>> &dp, int &k){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int l = i; l < j; l+=(k-1)){
            mini = min(mini, solve(i, l, prefix, dp, k) + solve(l+1, j, prefix, dp, k));
        }
        if((j-i) % (k-1) == 0){
            mini += prefix[j+1] - prefix[i];
        }
        return dp[i][j] = mini;
    }
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1) % (k-1) != 0) return -1;
        vector<vector<int>> dp(n, vector<int> (n , -1));
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; i++) prefix[i+1] += prefix[i] + stones[i];
        return solve(0, n-1, prefix, dp, k);
    }
};