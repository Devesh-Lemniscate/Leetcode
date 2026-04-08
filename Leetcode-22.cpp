/*
 * Problem 22: Generate Parentheses
 * Language: C++
 */
class Solution {
private:
    void helper(int n, vector<string> &ans, string s, int cnt1, int cnt2){
        if(cnt1 == cnt2 && cnt1+cnt2==2*n){
            ans.push_back(s);
            return;
        }
        if(cnt1<n) helper(n, ans, s+'(', cnt1+1, cnt2);
        if(cnt2<cnt1) helper(n, ans, s+')', cnt1, cnt2+1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, ans, "", 0, 0);
        return ans;
    }
};