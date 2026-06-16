/*
 * Problem 3612: Process String with Special Operations I (POTD)
 * Language: C++
 */
class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto ch: s){
            if(ch=='*' && res.size()) res.pop_back();
            else if(ch=='%' && res.size()) reverse(res.begin(), res.end());
            else if(ch=='#' && res.size()) res += res;
            else if(isalpha(ch))res.push_back(ch);
        }
        return res;
    }
};