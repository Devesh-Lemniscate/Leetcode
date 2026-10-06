/*
 * Problem 921: Minimum Add to Make Parentheses Valid (POTD)
 * Language: C++
 */
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ind = 0, n = s.size();
        int count = 0;
        stack<int> st;
        while(ind < n){
            if(s[ind] == '(') st.push(1);
            else if(st.size()) st.pop();
            else count++;
            ind++;
        }
        count += st.size();
        return count;
    }
};