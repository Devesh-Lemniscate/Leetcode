/*
 * Problem 3550: Smallest Index With Digit Sum Equal to Index (POTD)
 * Language: C++
 */
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int index = 0;
        for(auto num: nums){
            int sum = 0;
            while(num){
                sum += num % 10;
                num /= 10;
            }
            if(sum == index) return index;
            index++;
        }
        return -1;
    }
};