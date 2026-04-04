/*
 * Problem 2075: Decode the Slanted Ciphertext (POTD)
 * Language: C++
 */
class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int incr = (s.size() / rows) + 1;
        string ans;
        for(int i = 0; i < incr; i++){
            for(int j = 0; i+j < s.size(); j+=incr){
                ans.push_back(s[i+j]);
            }
        }
        for(int i = ans.size()-1; i >= 0 && ans[i]==' '; i--) ans.pop_back();
        return ans;
    }
};