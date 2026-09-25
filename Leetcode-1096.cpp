/*
 * Problem 1096: Brace Expansion II (POTD)
 * Language: C++
 */
class Solution {
private:
    unordered_set<string> helper(const unordered_set<string>& st1, const unordered_set<string>& st2) {
        unordered_set<string> res;
        for (auto s1 : st1) {
            for (auto s2 : st2) {
                res.insert(s1 + s2);
            }
        }
        return res;
    }

    unordered_set<string> solve(string &expression, int &i){
        unordered_set<string> total, curr = {""};
        while(i < expression.size() && expression[i] != '}'){
            if(expression[i] ==','){
                total.insert(curr.begin(), curr.end());
                curr = {""};
                i++;
            }else if(expression[i] == '{'){
                i++; 
                unordered_set<string> nextSet = solve(expression, i);
                i++; 
                curr = helper(curr, nextSet);
            }else{
                string s(1, expression[i]);
                curr = helper(curr, {s});
                i++;
            }
        }
        total.insert(curr.begin(), curr.end());
        return total;
    }
public:
    vector<string> braceExpansionII(string expression) {
        int index = 0;
        unordered_set<string> st = solve(expression, index);
        vector<string> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};