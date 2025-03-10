class Solution {
    public:
        int totalFruit(vector<int>& arr) {
            int n = arr.size();
            int i = 0, j = 0, maxLen = 0;
            unordered_map<int, int> mp;
            while(i<n && j<n){
                mp[arr[j]]++;
                while(mp.size()>2){
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0) mp.erase(arr[i]);
                    i++;
                }
                maxLen = max(maxLen, j-i+1);
                j++;
            }
            return maxLen;
        }
    };