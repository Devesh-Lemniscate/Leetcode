/*
 * Problem 739: Daily Temperatures
 * Language: C++
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n = temp.size();
        vector<int> ans;
        for(int i = n-1; i >= 0; i--){
            while(st.size() && temp[st.top()] <= temp[i]) st.pop();
            if(st.size()) ans.push_back(st.top()-i);
            else ans.push_back(0);
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};