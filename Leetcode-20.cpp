/*
 * Problem 20: Valid Parentheses
 * Language: C++
 */
class Solution {
public:
    bool isValid(string s) {
        string str;
        for(auto it: s){
            if(it == '(' || it == '{' || it == '[') str.push_back(it);
            else{
                if(str.size() && it == ')' && str.back() == '(') str.pop_back();
                else if(str.size() && it == '}' && str.back() == '{') str.pop_back();
                else if(str.size() && it == ']' && str.back() == '[') str.pop_back();
                else return false;
            }
        }
        if (str.size()) return false;
        return true;
    }
};