/*
 * Problem 66: Plus One (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 0;
        for(int i = 0; i < digits.size(); i++){
            digits[i] += (i==0?1:0) + carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            if(!carry) break;
        }
        if(carry) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};