/*
 * Problem 696: Count Binary Substrings (POTD)
 * Language: C++
 */
class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1, prev = 0, ans = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == s[i]) curr++;
            else{
                ans += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }
        return ans+min(curr, prev);
    }
};