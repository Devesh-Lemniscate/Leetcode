/*
 * Problem 2553: Separate the Digits in an Array (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        reverse(nums.begin(), nums.end());
        for(auto num: nums){
            while(num){
                result.push_back(num % 10);
                num /= 10;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};