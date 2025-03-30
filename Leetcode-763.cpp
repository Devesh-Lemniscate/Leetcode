class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int freq[26] = {0}, n = s.size();
            for(int i = 0; i < n; i++){
                freq[s[i]-'a'] = i;
            }
            vector<int> ans;
            int mx = freq[s[0]-'a'], idx = freq[s[0]-'a'], prev = 0;
            for(int i = 1; i < n; i++){
                if(i<=idx){
                    if(freq[s[i]-'a'] > mx){
                        mx = freq[s[i]-'a'];
                        idx = freq[s[i]-'a'];
                    }
                }else{
                    ans.push_back(mx-prev+1);
                    mx = freq[s[i]-'a'];
                    idx = freq[s[i]-'a'];
                    prev = i;
                }
            }
            ans.push_back(mx-prev+1);
            return ans;
        }
    };