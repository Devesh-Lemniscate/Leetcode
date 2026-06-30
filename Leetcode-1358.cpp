/*
 * Problem 1358: Number of Substrings Containing All Three Characters (POTD)
 * Language: C++
 */
class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3] = {0};
        int left = 0, right = 0;
        int n  = s.size();
        int count = 0;
        while(right < n){
            freq[s[right]-'a']++;
            while(freq[0] && freq[1] && freq[2]){
                count += n - right;
                freq[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return count;
    }
};