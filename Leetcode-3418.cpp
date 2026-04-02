/*
 * Problem 3418: Maximum Amount of Money Robot Can Earn (POTD)
 * Language: C++
 */
class Solution {
private:
    int dp[501][501][3];
    int helper(int i, int j, int chance, vector<vector<int>> &coins){
        int n = coins.size(), m = coins[0].size();
        
        if(i==n-1 && j==m-1){
            if (chance && coins[i][j] < 0) return 0;
            else return coins[i][j];
        }
        if(i >= n || j >= m) return -1e9;

        if(dp[i][j][chance] != -1e9) return dp[i][j][chance];
        int right = coins[i][j] + helper(i, j+1, chance, coins);
        int down = coins[i][j] + helper(i+1, j, chance, coins);
        int rightn = -1e9, downn = -1e9;
        if(chance && coins[i][j] < 0){
            rightn = helper(i, j+1, chance-1, coins);
            downn = helper(i+1, j, chance-1, coins);
        }
        return dp[i][j][chance] =max({right, down, rightn, downn});
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(int), -1e9);
        return helper(0, 0, 2, coins);
    }
};