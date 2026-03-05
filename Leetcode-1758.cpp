/*
 * Problem 1758: Minimum Changes To Make Alternating Binary String (POTD)
 * Language: C++
 */
class Solution {
public:
    int minOperations(string s) {
        int mini = INT_MAX, curr = 0;
        int n = s.size();
        curr = (s[0] != '1');
        char ch = '1';
        for(int i = 1; i < n; i++){
            if(s[i] == ch){
                curr++;
            }
            ch = (ch == '0') ? '1' : '0';
        }
        mini = min(mini, curr);
        curr = (s[0] == '1');
        ch = '0';
        for(int i = 1; i < n; i++){
            if(s[i] == ch){
                curr++;
            }
            ch = (ch == '0') ? '1' : '0';
        }
        mini = min(mini, curr);
        return mini;
    }
};