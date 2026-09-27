/*
 * Problem 1190: Reverse Substrings Between Each Pair of Parentheses (POTD)
 * Language: C++
 */
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                string temp;
                while(!st.empty() && st.top() != '('){
                    temp.push_back(st.top()); st.pop();
                }
                st.pop();
                int ind = temp.size(), curr = 0;
                while(curr < ind){
                    st.push(temp[curr++]);
                }
            }else st.push(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};