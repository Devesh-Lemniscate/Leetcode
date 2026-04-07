/*
 * Problem 1539: Kth Missing Positive Number
 * Language: C++
 */
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1, mid = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] - mid - 1 < k) low = mid+1;
            else high = mid-1;
        }
        return low + k;
    }
};