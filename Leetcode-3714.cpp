/*
 * Problem 3714: Longest Balanced Substring II (POTD)
 * Language: C++
 */
class Solution {
private:
    int helper(const string& s, char c1, char c2) {
        int maxi = 0;
        int diff = 0;         
        unordered_map<int, int> mp;
        mp[0] = -1; 
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != c1 && s[i] != c2) {
                mp.clear();
                mp[0] = i; 
                diff = 0;
            } else {
                if (s[i] == c1) diff++;
                else diff--; 
                if (mp.count(diff)) maxi = max(maxi, i - mp[diff]);
                else mp[diff] = i;
            }
        }
        return maxi;
    }

    int help(const string& s) {
        int maxi = 0;
        int ca = 0, cb = 0, cc = 0;
        
        map<pair<int, int>, int> mp;
        
        mp[{0, 0}] = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else if (s[i] == 'c') cc++;
            pair<int, int> key = {ca - cb, cb - cc};
            
            if (mp.count(key)) maxi = max(maxi, i - mp[key]);
            else mp[key] = i;
            
        }
        return maxi;
    }

public:
    int longestBalanced(string s) {
        int ans = 0;
        int n = s.length();

        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i-1]) curr++;
            else curr = 1;
            ans = max(ans, curr);
        }
        
        ans = max(ans, helper(s, 'a', 'b')); 
        ans = max(ans, helper(s, 'b', 'c')); 
        ans = max(ans, helper(s, 'a', 'c')); 
        
        ans = max(ans, help(s));
        
        return ans;
    }
};