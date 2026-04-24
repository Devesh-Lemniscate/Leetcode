/*
 * Problem 472: Concatenated Words
 * Language: C++
 */
class Solution {
private:
    bool dfs(string &word, unordered_set<string> &st, unordered_map<string, bool> &dp){
        if(dp.count(word)) return dp[word];
        for(int i = 1; i < word.size(); i++){
            string prefix = word.substr(0, i), suffix = word.substr(i);
            if(st.count(prefix) && (st.count(suffix) || dfs(suffix, st, dp))) return dp[word] = true;
        }
        return dp[word] = false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        unordered_map<string, bool> dp;
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            if(dfs(words[i], st, dp)) ans.push_back(words[i]);
        }
        return ans;
    }
};