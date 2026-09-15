/*
 * Problem 2472: Maximum Number of Non-overlapping Palindrome Substrings (POTD)
 * Language: C++
 */
class Solution {
private:
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int ind = 0;
        while(ind + k <= n){
            bool found = false;
            for(int index = ind + k - 1; index <= ind+k && index < n; index++){
                if(isPalindrome(s, ind, index)){
                    count++;
                    ind = index + 1;
                    found = true;
                    break;
                }
            }
            if(!found) ind++;
        }
        return count;
    }
};