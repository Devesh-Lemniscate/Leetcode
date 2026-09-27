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
                reverse(ans.begin(), ans.ed)
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