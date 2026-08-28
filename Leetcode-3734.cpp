/*
 * Problem 3734: Lexicographically Smallest Palindromic Permutation Greater Than Target (POTD)
 * Language: C++
 */
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26);
        for(auto it: s) freq[it-'a']++;
        int ind = 0, n = s.size();
        int count = 0, odd = -1;
        for(int i = 0; i < 26; i++){
            if(freq[i] & 1){
                count++;
                freq[i]--;
                odd = i;
            }
            freq[i] /= 2;
        }
        if((count > 1) || (n%2 == 0 && count > 0)) return "";


        string ans = "";
        while(ind < n/2 && freq[target[ind]-'a'] > 0){
            ans.push_back(target[ind]);
            freq[target[ind]-'a']--;
            ind++;
        }
        if(odd != -1 && ind == n/2 && target[ind]-'a' < odd){
            string temp = ans;
            reverse(ans.begin(), ans.end());
            temp.push_back((odd+'a'));
            return temp + ans;
        }

        if(ind == n/2){
            string first = ans, second = ans;
            reverse(second.begin(), second.end());
            if(odd != -1) first.push_back(odd+'a');
            first += second;
            if(first > target) return first;

            ind = n/2 - 1;
            if(ind >= 0)freq[target[ind]-'a']++;
            if(ans.size())ans.pop_back();
        }

        if(ind < 0) return "";
        bool flag = true;
        
        for(int i = target[ind]-'a'+1; i < 26; i++){
            if(freq[i] > 0){
                flag = false;
                ans.push_back(i+'a');
                freq[i]--;
                break;
            }
        }

        while(flag){
            cout << ans << " " << flag << " " << ind << endl;
            if(ans.size()){
                freq[ans.back()-'a']++;
                ans.pop_back();
            }
            ind--;
            if(ind < 0) break;
            for(int i = target[ind]-'a'+1; i < 26; i++){
                if(freq[i] > 0){
                    flag = false;
                    ans.push_back(i+'a');
                    freq[i]--;
                    break;
                }
            }
        }

        if(flag) return "";

        for(int i = 0; i < 26; i++){
            while(freq[i]--) ans.push_back(i+'a');
        }

        string temp = ans;
        reverse(ans.begin(), ans.end());
        if(odd!=-1){
            temp.push_back((odd+'a'));
            return temp + ans;
        }
        else return temp + ans;
    }
};