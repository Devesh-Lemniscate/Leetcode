/*
 * Problem 139: Word Break
 * Language: C++
 */
class Solution {
private:    
    int dp[301];
    bool helper(int idx, string &s, vector<string> & words){
        int len = s.size();
        if(idx == len) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int i = 0; i < words.size(); i++){
            string curr = words[i];
            if(curr.size() > len-idx) continue;
            bool flag = true;
            for(int j = 0; j < curr.size(); j++){
                if(curr[j] != s[idx+j]){
                    flag = false;
                    break;
                }
            }
            if(flag && helper(idx+curr.size(), s, words)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        return helper(0, s, wordDict);
    }
};