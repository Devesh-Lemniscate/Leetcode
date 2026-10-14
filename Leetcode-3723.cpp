/*
 * Problem 3723: Maximize Sum of Squares of Digits (POTD)
 * Language: C++
 */
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string str(num, '9');
        int currSum = 0, idx = -1;
        for(int i = 0; i < num; i++){
            if(currSum + (str[i]-'0') > sum){
                str[i] = sum-currSum + '0';
                idx = i;
                break;
            }
            currSum += str[i]-'0';
        }
        if(currSum < sum && idx == -1) return "";
        if(idx!=-1)for(int i = idx+1; i < num; i++) str[i] = '0';
        return str;
    }
};