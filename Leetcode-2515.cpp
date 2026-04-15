/*
 * Problem 2515: Shortest Distance to Target String in a Circular Array (POTD)
 * Language: C++
 */
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int len = words.size();
        for(int index = 0; index < len; index++){
            if(words[(startIndex+index)%len] == target) return index;
            if(words[(startIndex-index+len) % len] == target) return index;
        }
        return -1;
    }
};