/*
 * Problem 140: Word Break II
 * Language: C++
 */
class Solution {
private:    
    void helper(int idx, string &s, string word, unordered_set<string> &st, vector<string> &ans){
        int len = s.size();
        if(idx == len){
            word.pop_back();
            ans.push_back(word);
            return;
        }
        string temp;
        for(int i = idx; i < len; i++){
            temp.push_back(s[i]);
            if(st.count(temp)){
                helper(idx + temp.size(), s, word + temp + " ", st, ans);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> ans;
        helper(0, s, "", st, ans);
        return ans;
    }
};