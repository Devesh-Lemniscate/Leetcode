/*
 * Problem 1888: Minimum Number of Flips to Make the Binary String Alternating (POTD)
 * Language: C++
 */
class Solution {
private:
    int solve(string &s, string &str, int n){
        int need = INT_MAX, curr = 0;
        int left = 0, right = n;
        int len = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] != str[i]) curr++;
        }
        need = min(need, curr);
        while(right < len){
            if(s[left] != str[left]) curr--;
            if(s[right] != str[right]) curr++;
            need = min(need, curr);
            left++;
            right++;
        }
        return need;
    }
public:
    int minFlips(string s) {
        int n = s.size();
        s = s+s;
        string s1, s2;
        for(int i = 0; i < s.size(); i++){
            if(i&1){
                s1.push_back('0');
                s2.push_back('1');
            }else{
                s2.push_back('0');
                s1.push_back('1');
            }
        }
        return min(solve(s, s2, n), solve(s, s1, n));
    }
};