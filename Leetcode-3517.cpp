/*
 * Problem 3517: Smallest Palindromic Rearrangement I (POTD)
 * Language: C++
 */
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> frequency(26, 0);
        for(auto it: s) frequency[it-'a']++;
        string ans;
        char mid;
        for(int i = 0; i < 26; i++){
            if(frequency[i] % 2) mid = i+'a';
            int j = frequency[i]/2;
            while(j--){
                ans.push_back(i + 'a');
            }
        }
        if(s.size()&1) ans.push_back(mid);
        for(int i = 25; i >= 0; i--){
            int j = frequency[i]/2;
            while(j--){
                ans.push_back(i + 'a');
            }
        }
        return ans;
    }
};