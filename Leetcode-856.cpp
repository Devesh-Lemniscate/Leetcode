/*
 * Problem 856: Score of Parentheses (POTD)
 * Language: C++
 */
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);                        

        int index = 0, n = s.size();
        while(index < n){
            while(index < n && s[index] == ')' && st.size() > 1){
                int val = st.top();
                st.pop();
                if(val == 0) val = 1;
                else val *= 2;
                st.top() += val;           
                index++;
            }

            if(index < n && s[index] == '(') st.push(0);
            index++;
        }

        return st.top();
    }
};
