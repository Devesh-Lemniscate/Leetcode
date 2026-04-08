/*
 * Problem 3: Longest Substring Without Repeating Characters
 * Language: C++
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0, right = 0;
        int len = s.size();
        int maxi = 0;
        while(left < len && right < len){
            if(mp.count(s[right])){
                while(s[left] != s[right]){
                    mp[s[left]]--;
                    if(mp[s[left]] == 0) mp.erase(s[left]);
                    left++;
                }
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
            maxi = max(maxi, right-left+1);
            mp[s[right]]++;
            right++;
        }
        maxi = max(maxi, right-left);
        return maxi;
    }
};