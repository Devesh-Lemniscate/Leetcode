/*
 * Problem 2840: Check if Strings Can be Made Equal With Operations II (POTD)
 * Language: C++
 */
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> atOdd(26, 0), atEven(26, 0);
        for(int index = 0; index < s2.size(); index++){
            if(index & 1) atOdd[s2[index]-'a']++;
            else atEven[s2[index]-'a']++;
        } 
        for(int index = 0; index < s1.size(); index++){
            if((index & 1) && atOdd[s1[index]-'a'] > 0) atOdd[s1[index]-'a']--;
            else if(!(index & 1) && atEven[s1[index]-'a'] > 0) atEven[s1[index]-'a']--; 
            else return false;
        }
        return true;
    }
};