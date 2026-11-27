/*
 * Problem 3946: Maximum Number of Items From Sale I (POTD)
 * Language: C++
 */
class Solution {
public:
    int solve(int idx,vector<vector<int>> &items,vector<vector<int>> &dp,int budget,vector<int> &book,int rem){
        int n = items.size();
        if(idx == n){
            return budget/rem;
        }
        if(dp[idx][budget] != -1){
            return dp[idx][budget];
        }
        int skip = solve(idx+1,items,dp,budget,book,rem);
        int take = 0;
        int totalcost = items[idx][1];
        if(totalcost <= budget){
            take = book[idx] + solve(idx+1,items,dp,budget-totalcost,book,rem);
        }
        return dp[idx][budget] = max(skip,take);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> book(n,1);
        vector<vector<int>> dp(n,vector<int>(budget+1,-1));
        int rem = INT_MAX;
        for(int i=0;i<n;i++){
            rem = min(rem,items[i][1]);
            for(int j=0;j<n;j++){
                if(i != j && (items[j][0]%items[i][0] == 0)){
                    book[i]++;
                }
            }
        }
        int res = solve(0,items,dp,budget,book,rem);
        return res;
    }
};