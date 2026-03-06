/*
 * Problem 1784: Check if Binary String Has at Most One Segment of Ones (POTD)
 * Language: C++
 */
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = true;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == '1' && flag) continue;
            else if(s[i-1] == '0'){
                flag = false;
                continue;
            }
            else if(!flag) return false;
            else flag = false;
        }
        if(s[s.size()-1] == '1' && !flag) return flag;
        return true;
    }
};