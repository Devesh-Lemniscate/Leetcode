/*
 * Problem 3014: Minimum Number of Pushes to Type Word I (POTD)
 * Language: C++
 */
class Solution {
public:
    int minimumPushes(string word) {
        int len = word.size();
        int ans = 0;
        for(int i = 1; len > 0; len -= 8, i++){
            if(len >= 8)ans += 8 * i;
            else ans += len * i; 
        }
        return ans;
    }
};