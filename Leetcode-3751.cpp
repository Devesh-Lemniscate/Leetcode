/*
 * Problem 3751: Total Waviness of Numbers in Range I (POTD)
 * Language: C++
 */
class Solution {
private:
    int countWavy(int num){
        string s = to_string(num);
        int count = 0;
        for(int i = 1; i < s.size()-1; i++){
            if((s[i] > s[i-1] && s[i] > s[i+1]) || (s[i] < s[i-1] && s[i] < s[i+1])){
                count++;
            }
        }
        return count;
    }
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int i = num1; i <= num2; i++){
            count += countWavy(i);
        }
        return count;
    }
};