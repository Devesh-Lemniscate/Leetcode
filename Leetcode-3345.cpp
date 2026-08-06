/*
 * Problem 3345: Smallest Divisible Digit Product I (POTD)
 * Language: C++
 */
class Solution {
private:
    int sumOfDigit(int n){
        int sum = 1;
        while(n){
            sum *= (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    int smallestNumber(int n, int t) {
        while(1){
            int sum = sumOfDigit(n);
            if(sum % t == 0) return n;
            n++;
        }
        return -1;
    }
};