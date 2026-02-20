/*
 * Problem 761: Special Binary String (POTD)
 * Language: C++
 */
class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, i = 0;
        vector<string> ans;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '1') count++;
            else count--;
            if(count == 0){
                ans.push_back('1' + makeLargestSpecial(s.substr(i+1, j-1-i))+ '0');
                i = j+1;
            }
        }
        sort(ans.rbegin(), ans.rend());
        string res = "";
        for(int i = 0; i < ans.size(); i++) res += ans[i];
        return res;
    }
};