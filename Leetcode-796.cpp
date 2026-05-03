/*
 * Problem 796: Rotate String (POTD)
 * Language: C++
 */

class Solution {
    public:
        bool rotateString(string& s, string& goal) {
                return s.size()==goal.size() && (s+s).find(goal)!=-1;
                    }
                    };
1

