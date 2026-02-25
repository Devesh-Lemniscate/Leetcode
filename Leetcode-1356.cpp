/*
 * Problem 1356: Sort Integers by The Number of 1 Bits (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y){
            int num1 = x, num2 = y;
            int count1 = 0, count2 = 0;
            while(num1){
                count1 += num1 % 2;
                num1 /= 2;
            }
            while(num2){
                count2 += num2 % 2;
                num2 /= 2;
            }
            if(count1 == count2) return x < y;
            return count1 < count2;
        });
        return nums;
    }
};