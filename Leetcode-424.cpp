class Solution {
    public:
        int characterReplacement(string s, int k) {
            int i = 0, j = 0, maxLen = 0, maxFreq = 0;
            int arr[26] = {0};
            while(j < s.size()){
                arr[s[j]-'A']++;
                maxFreq = max(maxFreq, arr[s[j]-'A']);
                while(j-i+1-maxFreq > k){
                    arr[s[i]-'A']--;
                    maxFreq = 0;
                    for(int i = 0; i < 26; i++) maxFreq = max(maxFreq, arr[i]);
                    i++;
                }
                if(j-i+1-maxFreq <= k) maxLen = max(maxLen, j-i+1);
                j++;
            }
            return maxLen;
        }
    };