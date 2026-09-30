/*
 * Problem 1111: Maximum Nesting Depth of Two Valid Parentheses Strings (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int maxi = 0;
        stack<int> st;
        for(int i = 0; i < seq.size(); i++){
            if(seq[i] == '(') st.push(0);
            else{
                maxi = max(maxi, (int)st.size());
                st.pop();
            }
        }
        vector<int> ans(seq.size());
        maxi /= 2;
        for(int i = 0; i < seq.size(); i++){
            if(seq[i] == '('){
                st.push(0);
                if(st.size() <= maxi) ans[i] = 0;
                else ans[i] = 1;
            }
            else{
                if(st.size() <= maxi) ans[i] = 0;
                else ans[i] = 1;
                st.pop();
            }
        }
        return ans;
    }
};