/*
 * Problem 3889: Mirror Frequency Distance
 * Language: C++
 */
class Solution {
public:
    int mirrorFrequency(string s) {
        int sum = 0;
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;
        
        for(char c = 'a'; c <= 'm'; c++) {
            sum += abs(mp[c] - mp['z' - (c - 'a')]);
        }
        for(char c = '0'; c <= '4'; c++) {
            sum += abs(mp[c] - mp['9' - (c - '0')]);
        }
        
        return sum;
    }
};