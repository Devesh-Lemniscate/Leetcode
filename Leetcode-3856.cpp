/*
 * Problem 3856: Trim Trailing Vowels
 * Language: C++
 */
class Solution {
private:
    bool check(int index, string &s){
        char ch = s[index];
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    string trimTrailingVowels(string s) {
        int left = 0, right = s.size() - 1;
        for(int i = s.size() - 1; i >= 0; i--){
            if(check(i, s)) right--;
            else break;
        }
        string str = "";
        for(int i = left; i  <= right; i++) str += s[i];
        return str;
    }
};