class Solution {
    public:
        int numberOfSubstrings(string s) {
            int mp[3] = {0};
            int n = s.size();
            int i = 0, j = 0, ans = 0;
            while(j<n){
                mp[s[j]-'a']++;
                while(mp[0] && mp[1] && mp[2]){
                    ans += (n-j);
                    mp[s[i]-'a']--;
                    i++;
                }
                j++;
            }
            return ans;
        }
    }; 