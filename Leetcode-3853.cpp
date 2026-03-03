/*
 * Problem 3853: Merge Close Characters
 * Language: C++
 */
class Solution {
public:
    string mergeCharacters(string s, int k) {
        vector<int> indexes(26, -1);
        int n = s.size(), idx = 0;
        string ans = "";
        for(int i = 0; i < n; i++){
            if(indexes[s[i]-'a'] == -1){
                ans.push_back(s[i]);
                indexes[s[i] - 'a'] = idx;
                idx++;
            }else{
                if(idx > indexes[s[i] - 'a'] + k){
                    ans.push_back(s[i]);
                    indexes[s[i] - 'a'] = idx++;
                }
            }
        }
        return ans;
    }
};