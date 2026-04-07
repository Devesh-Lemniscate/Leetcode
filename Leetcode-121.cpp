/*
 * Problem 121: Best Time to Buy and Sell Stock
 * Language: C++
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, maxi = 0;
        for(int i = 0; i < prices.size(); i++){
            mini = min(mini, prices[i]);
            maxi = max(maxi, prices[i]-mini);
        }
        return maxi;
    }
};