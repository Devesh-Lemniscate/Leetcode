/*
 * Problem 678: Valid Parenthesis String (POTD)
 * Language: C++
 */
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        int count = 0;
        for(auto it: s){
            if(it == '(') st.push(1);
            else if(it == ')'){
                if(st.size()) st.pop();
                else if(count > 0) count--;
                else return false;
            }else count++;
        }
        return st.size() <= count;
    }
};