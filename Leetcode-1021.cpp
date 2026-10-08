/*
 * Problem 1021: Remove Outermost Parentheses (POTD)
 * Language: C++
 */
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<int> st;
        int ind = 0, n = s.size();
        while(ind < n){
            if(s[ind] == '('){
                if(st.size()) ans.push_back('(');
                st.push(1);
            }else{
                st.pop();
                if(st.size()) ans.push_back(')');
            }
            ind++;
        }
        return ans;
    }
};