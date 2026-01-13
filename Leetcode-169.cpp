/*
 * Problem 169: Majority Element
 * Language: C++
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int len = nums.size();
        int count = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] != num && count) count--;
            else if(nums[i] == num) count++;
            else if(nums[i] != num && count == 0){
                num = nums[i];
                count++;
            }
        }
        return num;
    }
};