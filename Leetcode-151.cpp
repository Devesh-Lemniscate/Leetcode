/*
 * Problem 151: Reverse Words in a String
 * Language: C++
 */
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int len = s.size();
        int left = 0, right = 0;
        int index = 0;
        while(index < len){
            while(index < len && s[index] == ' ') index++;
            if(index == len) break;
            while(index < len && s[index] != ' ') s[right++] = s[index++];
            reverse(s.begin() + left, s.begin()+right);
            s[right++] = ' ';
            left = right;
            index++;
        }
        s.resize(right-1);
        return s;
    }
};
// "  dlrow olleh  "

// "world "