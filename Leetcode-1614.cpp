/*
 * Problem 1614: Maximum Nesting Depth of the Parentheses (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxDepth(string s) {
        string str;
        int maxi = 0;
        for(auto i: s){
            if(i == '(') str.push_back(i);
            else if(i == ')'){
                maxi = max(maxi, (int)str.size());
                str.pop_back();
            }
        }
        return maxi;
    }
};