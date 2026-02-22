/*
 * Problem 868: Binary Gap (POTD)
 * Language: C++
 */
class Solution {
public:
    int binaryGap(int n) {
        int first = -1;
        int maxi = 0;
        for(int i = 31; i >= 0; i--){
            if((1 << i) & n){
                if(first == -1) first = i;
                else{
                    maxi = max(maxi, first - i);
                    first = i;
                }
            }
        }
        return maxi;
    }
};