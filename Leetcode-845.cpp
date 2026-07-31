/*
 * Problem 845: Longest Mountain in Array
 * Language: C++
 */
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> up(n), down(n);
        for(int i = n-2; i >= 0; i--) if(arr[i] > arr[i+1]) down[i] = down[i+1] + 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i > 0 && arr[i] > arr[i-1]) up[i] = up[i-1] + 1;
            if(up[i] && down[i]) ans = max(ans, up[i] + down[i] + 1);
        }
        return ans;
    }

};