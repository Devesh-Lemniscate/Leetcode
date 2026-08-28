/*
 * Problem 3720: Lexicographically Smallest Permutation Greater Than Target (POTD)
 * Language: C++
 */
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq1(26), freq2(26);
        int n = s.size();
        for(int i = 0; i < n; i++){
            freq1[s[i] - 'a']++;
            freq2[target[i] - 'a']++;
        }
        string ans = "";
        int i;
        for(i = 0; i < n; i++){
            if(freq1[target[i]-'a'] > 0){
                ans.push_back(target[i]);
                freq1[target[i]-'a']--;
            }
            else break;
        }
        bool flag = true;
        if(i==n){
            i = n-1;
            freq1[target[n-1]-'a']++;
            ans.pop_back();
        }
        for(int j = target[i]-'a'+1; j < 26; j++){
            if(freq1[j] > 0){
                flag = false;
                ans.push_back((j+'a'));
                freq1[j]--;
                break;
            }
        }
        
            while(flag){
                if(ans.size()){
                    freq1[ans.back()-'a']++;
                    ans.pop_back();
                }
                i--;
                if(i < 0) break;
                for(int j = target[i]-'a'+1; j < 26; j++){
                    if(freq1[j] > 0){
                        flag = false;
                        ans.push_back((j+'a'));
                        freq1[j]--;
                        break;
                    }
                }
            }
            if(flag) return "";
        
        for(int k = 0; k < 26; k++){
            while(freq1[k] > 0){
                ans.push_back((k+'a'));
                freq1[k]--;
            }
        }
        return ans;
    }
};