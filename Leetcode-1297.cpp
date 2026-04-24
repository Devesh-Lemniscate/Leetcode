/*
 * Problem 1297: Maximum Number of Occurrences of a Substring
 * Language: C++
 */
class Solution {
public:
    int maxFreq(string s, int maxi, int minSize, int maxSize) {
        string str = "";
        unordered_map<char, int> mp1;
        unordered_map<string, int> mp2;
        int maxe = 0;
        for(int i = 0; i < s.size(); i++){
            str.push_back(s[i]);
            mp1[s[i]]++;
            while(str.size() > minSize){
                char curr = str[0];
                mp1[curr]--;
                if(mp1[curr] == 0) mp1.erase(curr);
                str = str.substr(1);
            }
            if(str.size() >= minSize && str.size() <= maxSize){
                if(mp1.size() <= maxi){
                    mp2[str]++;
                    maxe = max(maxe, mp2[str]);
                }
            }
        }
        return maxe;
    }
};