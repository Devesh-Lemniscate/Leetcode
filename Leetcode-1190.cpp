/*
 * Problem 1190: Reverse Substrings Between Each Pair of Parentheses (POTD)
 * Language: C++
 */
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string ans;
        for(auto ch: s){
            if(ch == ')'){
                reverse(ans.begin(), ans.end());
                ans = st.top() + ans;
                st.pop();
            }else if(ch == '('){
                st.push(ans);
                ans.clear();
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};