/*
 * Problem 3783: Mirror Distance of an Integer (POTD)
 * Language: C++
 */
class Solution {
public:
    int mirrorDistance(int n) {
        int y = n, x = 0;
        while(y){
            x = x*10 + y % 10;
            y /= 10;
        }
        return abs(x-n);
    }
};