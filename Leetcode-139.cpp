/*
 * Problem 139: Word Break
 * Language: C++
 */
class Solution {
private:    
    bool helper(int idx, string &s, vector<string> & words){
        int len = s.size();
        if(idx == len) return true;
        for(int i = 0; i < words.size(); i++){
            string curr = words[0];
            if(curr.size() > len-idx) continue;
            int prev = idx;
            bool flag = true;
            for(int j = 0; j < curr.size(); j++){
                if(curr[j] != s[idx]){
                    flag = false;
                    break;
                }else idx++;
            }
            if(!flag) idx = prev;
            if(idx == len) return true;
            if(helper(idx, s, words)) 
        }
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(0, s, wordDict);
    }
};