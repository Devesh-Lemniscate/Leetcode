/*
 * Problem 189: Rotate Array
 * Language: C++
 */
class Solution {

private:
    void rev(vector<int> &nums, int i, int j){
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++; j--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        if(k==0) return;
        reverse(nums.begin(), nums.end());
        rev(nums, 0, k-1);
        rev(nums, k, len-1);
    }
};
// 1 2 3 4 5 6 7
// 7 6 5 4 3 2 1


// -1 -100 3 99
// 99 3 -100 -1