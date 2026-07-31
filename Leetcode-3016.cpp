/*
 * Problem 3016: Minimum Number of Pushes to Type Word II (POTD)
 * Language: C++
 */
class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<int, char>> freq(26);
        for(auto it: word){
            freq[it-'a'] = {freq[it-'a'].first + 1, it};
        }
        sort(freq.rbegin(), freq.rend());
        for(int i = 1; i < 26; i++) freq[i].first += freq[i-1].first;
        int ans = 0;
        for(int i = 0, j = 1; i < 26; i += 8, j++){
            if(i + 8 > 26){
                ans += (freq[25].first - freq[i-1].first) * j;
            }else{
                ans += (freq[i+7].first - (i > 0 ? freq[i-1].first : 0)) * j;
            }
        }
        return ans;
    }
};