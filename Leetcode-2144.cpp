/*
 * Problem 2144: Minimum Cost of Buying Candies With Discount
 * Language: C++
 */
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int sum = 0;
        if(cost.size() <= 2) return accumulate(cost.begin(), cost.end(), 0);
        int i;
        for(i = cost.size()-1; i >= 0; i-=3){
            sum += cost[i];
            if(i-1 >= 0) sum += cost[i-1];
        }
        while(i >= 0) sum += cost[i--];
        return sum;
    }
};