/*
 * Problem 3813: Vowel-Consonant Score
 * Language: C++
 */
class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for(auto &it: s){
            if(it == 'a' || it =='e' || it == 'i' || it == 'o' || it == 'u' )v++;
            else if(it-'a' >= 0 && it-'a' <=26)c++;
        }
        if(c > 0) return v / c;
        else return 0;
    }
};