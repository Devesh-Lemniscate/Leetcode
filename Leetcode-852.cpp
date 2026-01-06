/*
 * Problem 852: Peak Index in a Mountain Array
 * Language: C++
 */
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size(), l = 0, h = n-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(m==0) return m+1;
            if(arr[m-1] < arr[m] && arr[m+1]<arr[m]) return m;
            else if(arr[m-1] < arr[m]) l = m+1;
            else if(arr[m+1]<arr[m]) h = m-1;
            m=l+(h-l)/2;
        }
        return -1;
    }
};