/*
 * Problem 650: 2 Keys Keyboard
 * Language: C++
 */
class Solution {
public:
    int minSteps(int n) {
        int sum = 0;
        for(int i = 2; i <= n; i++){
            while(n % i == 0){
                n /= i;
                sum += i;
            }
        }
        return sum;
    }
};