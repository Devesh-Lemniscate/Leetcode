/*
 * Problem 139: Word Break
 * Language: C++
 */
class Solution {
private:
    bool isPossible(int index, string &s, vector<string> &words, vector<int> &memo){
        int len = s.size();
        if(index == len) return true;
        if(memo[index] != -1) return memo[index];
        for(int idx = 0; idx < words.size(); idx++){
            string current = words[idx];
            if(len - idx < current.size()) continue;
            bool canTake = true;
            for(int ind = 0; ind < current.size(); ind++){
                if(current[ind] != s[index + ind]){
                    canTake = false;
                    break;
                }
            }
            if(canTake && isPossible(index + current.size(), s, words, memo)) return memo[index] = true;
        }
        return memo[index] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<int> memo(len+1, -1);
        return isPossible(0, s, wordDict, memo);
    }
};