/*
 * Problem 1021: Remove Outermost Parentheses (POTD)
 * Language: C++
 */
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count = 0;
        int ind = 0, n = s.size();
        while(ind < n){
            if(s[ind] == '('){
                if(count > 0) ans.push_back('(');
                count++;
            }else{
                count--;
                if(count > 0) ans.push_back(')');
            }
            ind++;
        }
        return ans;
    }
};