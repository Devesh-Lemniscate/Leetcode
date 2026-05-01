/*
 * Problem 3912: Valid Elements in an Array
 * Language: C++
 */
class Solution {
private:
    bool isValid(int position, vector<int> &nums){
        bool greaterThanRight = true, greaterThanLeft = true;
        for(int index = 0; index < position; index++){
            if(nums[index] >= nums[position]){
                greaterThanRight = false;
                break;
            }
        }
        for(int index = nums.size()-1; index > position; index--){
            if(nums[index] >= nums[position]){
                greaterThanLeft = false;
                break;
            }
        }
        return greaterThanRight || greaterThanLeft;
    }
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> validElements;
        int len = nums.size();

        if(len == 1) return nums;

        validElements.push_back(nums[0]);

        for(int index = 1; index < len-1; index++){
            if(isValid(index, nums)){
                validElements.push_back(nums[index]);
            }
        }
        validElements.push_back(nums[len-1]);
        return validElements;
    }
};