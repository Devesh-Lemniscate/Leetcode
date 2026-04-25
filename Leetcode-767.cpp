/*
 * Problem 767: Reorganize String
 * Language: C++
 */
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> mp(26);
        int maxi = 0;
        for(auto it: s){
            mp[it-'a']++;
            if(mp[it-'a'] > mp[maxi]) maxi = it-'a';
        }
        if(2*mp[maxi] - 1 > s.size()) return "";
        int i = 0;
        while(mp[maxi]){
            s[i] = 'a'+maxi;
            i+=2;
            mp[maxi]--;
        }
        for(int j = 0; j < 26; j++){
            while(mp[j]){
                if(i >= s.size()) i = 1;
                s[i] = ('a'+j);
                mp[j]--;
                i+=2;
            }
        }
        return s;
    }
};