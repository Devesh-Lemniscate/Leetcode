/*
 * Problem 2073: Time Needed to Buy Tickets
 * Language: C++
 */
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum = 0;
        for(int i = 0; i < tickets.size(); i++){
            if (i <= k) sum += min(tickets[k], tickets[i]);
            else sum += min(tickets[k] - 1, tickets[i]);
        }
        return sum;
    }
};