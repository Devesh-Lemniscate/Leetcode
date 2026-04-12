/*
 * Problem 42: Trapping Rain Water
 * Language: C++
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int lmax = 0, rmax = 0;
        int left = 0, right = len-1;
        int sum = 0;
        while(left < right){
            if(height[left] < height[right]){
                lmax = max(lmax, height[left]);
                sum += lmax - height[left];
                left++;
            }else{
                rmax = max(rmax, height[right]);
                sum += rmax - height[right];
                right--;
            }
        }
        return sum;
    }
};