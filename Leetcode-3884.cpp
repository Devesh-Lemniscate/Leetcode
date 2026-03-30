/*
 * Problem 3884: First Matching Character From Both Ends
 * Language: C++
 */
class Solution {
public:
    int firstMatchingIndex(string s) {
        int left = 0, right = s.size()-1;
        while(left <= right){
            if(s[left] == s[right]) return left;
            left++;
            right--;
        }
        return -1;
    }
};