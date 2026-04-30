/*
 * Problem 32: Longest Valid Parentheses
 * Language: C++
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        for(int i  = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(i);
            else{
                if(st.size()) st.p
            }
        }
    }
};