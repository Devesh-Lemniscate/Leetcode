/*
 * Problem 2839: Check if Strings Can be Made Equal With Operations I (POTD)
 * Language: C++
 */
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int len = s1.size();
        for(int index = 0; index < len - 2; index++){
            if(s1[index] != s2[index]){
                swap(s1[index], s1[index+2]);
            }

            if(s1[index] != s2[index]) return false;
        }
        if(s1[len-2] == s2[len-2] && s1[len-1] == s2[len-1]) return true;
        return false;
    }
};