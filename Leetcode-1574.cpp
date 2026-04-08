/*
 * Problem 1574: Shortest Subarray to be Removed to Make Array Sorted
 * Language: C++
 */
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int len = arr.size();
        int left = 0;
        while (left + 1 < len && arr[left] <= arr[left + 1]) left++;
        if (left == len - 1) return 0;
        int right = len - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) right--;
        
        int mini = min(len - left - 1, right);
        
        int i = 0;
        int j = right;
        
        while (i <= left && j < len) {
            if (arr[i] <= arr[j]) {
                mini = min(mini, j - i - 1);
                i++;
            } else j++; 
        }
        
        return mini;
    }
};