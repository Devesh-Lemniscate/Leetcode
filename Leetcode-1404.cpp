/*
 * Problem 1404: Number of Steps to Reduce a Number in Binary Representation to One (POTD)
 * Language: C++
 */
class Solution {
public:
    int numSteps(string s) {
        int carry = 0;
        int steps = 0;
        for(int index = s.size()-1; index > 0; index--){
            if(s[index] == '0' && carry == 0) steps++;
            else if(s[index] == '1' && carry == 1) steps++;
            else if(s[index] == '0' && carry == 1){
                steps += 2;
            }else if(s[index] == '1' && carry == 0){
                steps += 2;
                carry = 1;
            }
        }
        return steps + carry;
    }
};