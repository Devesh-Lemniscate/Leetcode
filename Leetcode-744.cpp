/*
 * Problem 744: Find Smallest Letter Greater Than Target (POTD)
 * Language: C++
 */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto iter = upper_bound(letters.begin(), letters.end(), target);
        if(iter == letters.end()) return letters[0];
        else return *iter;
    }
};