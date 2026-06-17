/*
 * Problem 3614: Process String with Special Operations II (POTD)
 * Language: C++
 */
class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(auto ch: s){
            if(ch == '*') len = max(0LL, len-1);
            else if(ch == '#') len *= 2;
            else if(ch == '%') continue;
            else len++; 
        }
        if(len <= k) return '.';

        for(int i = s.size()-1; i >= 0; i--){
            char ch = s[i];
            if(ch=='*') len++;
            else if(ch == '#'){
                len /= 2;
                k %= len;
            }else if(ch == '%'){
                k = len - k - 1;
            }else{
                len--;
                if(k == len) return ch;
            }
        }


        return '.';
    }
};