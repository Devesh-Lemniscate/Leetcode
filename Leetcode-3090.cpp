/*
 * Problem 3090: Maximum Length Substring With Two Occurrences (POTD)
 * Language: C++
 */
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> frequency;
        int maxLen = INT_MIN;
        int right, left;
        for(right = 0, left = 0; right < s.size(); right++){
            char current = s[right];
            frequency[current]++;
            while(left < right && frequency[current] > 2){
                frequency[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            
        }
        maxLen = max(maxLen, right-left);
        return maxLen;
    }
};