/*
 * Problem 84: Largest Rectangle in Histogram (POTD)
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
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) nextSmaller[i] = 
            else nextSmaller[i] = st.top();
        }
        while(!st.empty()) st.pop();

        for(int i = 1; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty())
            else prevSmaller[i] = st.top();
        }

        int area = 0;
        for(int i = 0; i < n; i++){
            area = max(area, heights[i] * (nextSmaller[i] - prevSmaller[i]));
        }
        return area;
    }
};