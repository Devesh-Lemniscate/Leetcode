/*
 * Problem 17: Letter Combinations of a Phone Number
 * Language: C++
 */
class Solution {
private:
    void findCombinations(int index, string &digits, unordered_map<char, string> &mp, vector<string> &ans, string current){
        if(current.size() == digits.size()){
            ans.push_back(current);
            return;
        }
        for(auto digit: mp[digits[index]]){
            findCombinations(index+1, digits, mp, ans, current + digit);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        findCombinations(0, digits, mp, ans, "");
        return ans;
    }
};