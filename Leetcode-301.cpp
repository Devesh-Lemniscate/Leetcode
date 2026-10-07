/*
 * Problem 301: Remove Invalid Parentheses (POTD)
 * Language: C++
 */
class Solution {
private:
    void helper(string &curr, int i, int cnt, string &s, unordered_set<string>& ans, int count){
        if(s.size() == i){
            if(cnt == 0 && count == 0) ans.insert(curr);  
            return;
        }

        if(s[i] == '('){
            curr.push_back(s[i]);
            helper(curr, i+1, cnt+1, s, ans, count);
            curr.pop_back();

            if(count - 1 >= 0) helper(curr, i+1, cnt, s, ans, count - 1);
            
        } else if(s[i] == ')'){
            if(cnt - 1 >= 0){
                curr.push_back(s[i]);
                helper(curr, i+1, cnt-1, s, ans, count);
                curr.pop_back();
            }

            if(count - 1 >= 0) helper(curr, i+1, cnt, s, ans, count - 1);
            
        } else{
            curr.push_back(s[i]);
            helper(curr, i+1, cnt, s, ans, count);
            curr.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        stack<int> st;
        int ind = 0, n = s.size();
        int count = 0;

        while(ind < n){
            if(s[ind] == '('){
                st.push(1);
            } else if(s[ind] == ')'){
                if(st.size()) st.pop();
                else count++;
            }
            ind++;
        }
        count += st.size();

        string curr = "";
        helper(curr, 0, 0, s, ans, count);
        return vector<string>(ans.begin(), ans.end());
    }
};