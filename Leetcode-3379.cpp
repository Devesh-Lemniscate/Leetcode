/*
 * Problem 3379: Transformed Array (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len);
        for(int index = 0; index < len; index++){
            if(nums[index] == 0) result[index] = 0;
            else if(nums[index] < 0){
                int currentIndex = index + nums[index];
                currentIndex = ((currentIndex % len) + len) % len;
                result[index] = nums[currentIndex];
            }
            else{
                int currentIndex = index + nums[index];
                currentIndex = currentIndex % len;
                result[index] = nums[currentIndex];
            }
            
        }
        return result;
    }
};