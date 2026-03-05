/*
 * Problem 3844: Longest Almost-Palindromic Substring
 * Language: C++
 */
class Solution {
private:
    int findMax(int left, int right, string &s) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        
        int maxi = 0;
        
        if (left >= 0) {
            int l1 = left - 1, r1 = right;
            while (l1 >= 0 && r1 < n && s[l1] == s[r1]) {
                l1--;
                r1++;
            }
            maxi = max(maxi, r1 - l1 - 1);
        } else {
            maxi = max(maxi, right - left - 1);
        }
        
        if (right < n) {
            int l2 = left, r2 = right + 1;
            while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                l2--;
                r2++;
            }
            maxi = max(maxi, r2 - l2 - 1);
        } else {
            maxi = max(maxi, right - left - 1);
        }
        
        return maxi;
    }

public:
    int almostPalindromic(string s) {
        int n = s.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, findMax(i, i, s));
            if (i + 1 < n) {
                maxi = max(maxi, findMax(i, i + 1, s));
            }
        }
        return maxi;
    }
};