/*
 * Problem 121: Best Time to Buy and Sell Stock
 * Language: C++
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], maxi = 0;
        for(int i = 1; i < prices.size(); i++){
            mini = min(mini, prices[i]);
            maxi = max(maxi, prices[i]-mini);
        }
        return maxi;
    }
};