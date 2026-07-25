/*
 * Problem 3536: Maximum Product of Two Digits (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxProduct(int n) {
        int max1 = -1, max2 = -1;
        while(n){
            int dig = n % 10;
            if(max1 == -1 && max2==-1){
                max1 = dig;
            }else{
                if(dig >= max1){
                    max2 = max1;
                    max1 = dig;
                }else if(dig > max2){
                    max2 = dig;
                }
            }
            n /= 10;
        }
        return max1 * max2;
    }
};