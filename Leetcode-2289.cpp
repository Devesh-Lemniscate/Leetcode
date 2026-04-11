/*
 * Problem 2289: Steps to Make Array Non-decreasing
 * Language: C++
 */
class Solution {
public:
    int totalSteps(vector<int>& nums) {
       stack<pair<int, int>> st;
       int maxi = 0;
       for(auto num: nums){
            int curr = 0;
            while(st.size() && st.top().first <= num){
                curr = max(curr, st.top().second);
                st.pop();
            }
            if(st.empty()) curr = 0;
            else curr++;
            maxi = max(maxi, curr);
            st.push({num, curr});
       }
       return maxi; 
    }
};