/*
 * Problem 3474: Lexicographically Smallest Generated String (POTD)
 * Language: C++
 */
class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<char> ans(n+m-1, '.');
        
        for(int i = 0; i< n; i++){
            if(str1[i] == 'T'){
                for(int j = i; j < i+m; j++){
                    if(ans[j]=='.' || ans[j]==str2[j-i]){
                        ans[j] = str2[j-i];
                    }else return "";
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                bool flag = true;
                for(int j = i; j < i+m; j++){
                    if(ans[j]==str2[j-i]){
                        ans[j] = str2[j-i];
                    }else flag = false;
                }
                if(flag) return "";
            }
        }
        
        for(int i = 0; i < n + m - 1; i++){  
            if(ans[i] == '.'){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    ans[i] = ch;
                    bool isValid = true;
                    
                    for(int k = max(0, i - m + 1); k <= min(n - 1, i); k++){
                        if(str1[k] == 'F'){
                            bool match = true;
                            for(int j = 0; j < m; j++){
                                if(ans[k+j] != str2[j]){
                                    match = false;
                                    break; 
                                }
                            }
                            if(match){ 
                                isValid = false; 
                                break;
                            }
                        }
                    }
                    if(isValid) break; 
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                bool match = true;
                for(int j = 0; j < m; j++){
                    if(ans[i+j] != str2[j]) { match = false; break; }
                }
                if(match) return "";
            }
        }
        
        string s;
        for(auto it: ans) s.push_back(it);
        return s;
    }
};