class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int arr[256] = {0};
            int ans = 0;
            for(int i = 0, j = 0; i < s.size(); i++){
                arr[(int)(s[i])]++;
                while(arr[s[i]] > 1){
                    arr[s[j]]--;
                    j++;
                }
                ans = max(ans, i-j+1);
            }
            return ans;
        }
    };