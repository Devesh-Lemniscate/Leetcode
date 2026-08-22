/*
 * Problem 3622: Check Divisibility by Digit Sum and Product (POTD)
 * Language: C++
 */
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int num = n;
        while(n){
            int digit = n % 10;
            n /= 10;
            sum += digit;
            product *= digit;
        }
        return !(num % (sum + product));
    }
};