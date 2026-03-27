/*
 * Problem 1616: Split Two Strings to Make Palindrome
 * Language: C++
 */
class Solution {
private:
    bool check(string &a, string &b){
        int i = 0, j = b.size()-1;
        int len = a.size();
        while(a[i] == b[j] && i < j){
            i++; j--;
        }
        int f1 = true, f2 = true;
        int l = i, r = j;
        while(l < r){
            if(len - l*2 == 1) break;
            if(b[l] != b[r]) f1 = false;
            l++; r--;
        }
        l = i, r= j;
        while(l < r){
            if(len - l*2 == 1) break;
            if(a[l] != a[r]) f2 = false;
            l++; r--;
        }
        return f1 || f2;
    }
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b,a);
    }
};