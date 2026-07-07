/*
 * Problem 3754: Concatenate Non-Zero Digits and Multiply by Sum I (POTD)
 * Language: C++
 */
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0, sum = 0, exp = 0;
        while(n){
            if(n % 10) num = num + (n % 10) * pow(10, exp++);
            sum += (n % 10);
            n /= 10;
        }
        return num * sum;
    }
};