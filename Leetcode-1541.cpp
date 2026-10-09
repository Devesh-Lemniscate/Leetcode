/*
 * Problem 1541: Minimum Insertions to Balance a Parentheses String (POTD)
 * Language: C++
 */
class Solution {
public:
    int minInsertions(string s) {
        int ind = 0;
        int n = s.size();
        stack<int> st;
        int count = 0;
        while(ind < n){
            if(s[ind] == '(') st.push(1);
            else{
                if(!st.empty() && ind+1 < n && s[ind] == ')' && s[ind+1] == ')'){
                    st.pop();
                    ind++;
                }else if(!st.empty() && ((ind+1 >= n) || (ind + 1 < n && s[ind+1] != ')'))){
                    count++;
                    st.pop();
                }
                else if(st.empty()){
                    if(ind+1 < n && s[ind] == ')' && s[ind+1] == ')'){
                        count++;
                        ind++;
                    }
                    else count += 2;
                }
            }
            ind++;
        }
        count += st.size() * 2;
        return count;
    }
};