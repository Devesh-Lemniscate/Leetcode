/*
 * Problem 84: Largest Rectangle in Histogram
 * Language: C++
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmaller(n), prevSmaller(n);
        stack<int> st;
        st.push(n);
        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && heights[st.top()] ){

            }
        }
    }
};