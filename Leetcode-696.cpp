/*
 * Problem 696: Count Binary Substrings
 * Language: C++
 */
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> freq;
        int cnt = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]) cnt++;
            else{
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);
        int maxi = 0;
        for(int i = 1; i < freq.size(); i++){
            maxi += min(freq[i], freq[i-1]);
        }
        return maxi;
    }
};