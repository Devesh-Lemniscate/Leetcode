/*
 * Problem 2452: Words Within Two Edits of Dictionary (POTD)
 * Language: C++
 */
class Solution {
private:
    bool check(string s, vector<string> &dict){
        for(auto it: dict){
            int cnt = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i]!=it[i]) cnt++;
            }
            if(cnt <= 2) return true;
        }
        return false;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto it: queries){
            if(check(it, dictionary)) ans.push_back(it);
        }
        return ans;
    }
};