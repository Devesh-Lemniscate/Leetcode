/*
 * Problem 3882: Minimum XOR Path in a Grid
 * Language: C++
 */
class Solution {
public:    
    int helper(int i,int j,int val,vector<vector<int>> &grid,int n,int m,vector<vector<vector<int>>> &dp){
        if(i==n-1 && j==m-1) return val^grid[i][j];
        if(dp[i][j][val]!=-1) return dp[i][j][val];
        int ans=1e9;
        if(i+1<n) ans=min(ans,helper(i+1,j,val^grid[i][j],grid,n,m,dp));
        if(j+1<m) ans=min(ans,helper(i,j+1,val^grid[i][j],grid,n,m,dp));
        return dp[i][j][val]=ans;
    }

    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(1025,-1)));
        return helper(0,0,0,grid,n,m,dp);
    }
};