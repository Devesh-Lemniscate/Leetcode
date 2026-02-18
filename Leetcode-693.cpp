/*
 * Problem 693: Binary Number with Alternating Bits (POTD)
 * Language: C++
 */
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int index = 31;
        while(index >= 0){
            if((1 << index) & n) 
                break;
            index--;
        }
        if(index == 0) return true;
        bool flag = false;
        while(index >= 0){
            if(((1 << index) & n) && !flag) flag = !flag;
            else if((((1 << index) & n) == 0) && flag) flag = !flag;
            else return false;
            index--;
        }
        return true;
    }
};