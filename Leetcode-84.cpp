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
        st.push(n-1);
        nextSmaller[n-1] = n;
        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) nextSmaller[i] = n;
            else nextSmaller[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(0);
        prevSmaller[0] = n;
        for(int i = 1; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) prevSmaller[i] = -1;
            else prevSmaller[i] = st.top();
            st.push(i);
        }

        int area = 0;
        for(int i = 0; i < n; i++){
            area = max(area, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }
        return area;
    }
};