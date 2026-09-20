/*
 * Problem 3498: Reverse Degree of a String (POTD)
 * Language: C++
 */
class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0, ind = 1;
        for(auto i: s){
            sum += (26 - (i-'a')) * (ind++);
        }
        return sum;
    }
};