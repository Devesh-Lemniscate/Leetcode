/*
 * Problem 327: Count of Range Sum
 * Language: C++
 */
class Solution {
private:
    int solve(vector<long long> &pref, vector<long long> &temp, int left, int right, int lower, int upper){
        if(left >= right) return 0;
        int mid = left + (right - left) / 2;
        int cnt = solve(pref, temp, left, mid, lower, upper) + solve(pref, temp, mid+1, right, lower, upper);
        int start = left, end = left;
        
        for (int i = mid + 1; i <= right; i++) {
            while (start <= mid && pref[start] < pref[i] - upper) start++;
            while (end <= mid && pref[end] <= pref[i] - lower) end++;
            cnt += (end - start);
        }

        int i = left;    
        int j = mid + 1; 
        int k = left;      
        
        while (i <= mid && j <= right) {
            if (pref[i] <= pref[j]) {
                temp[k++] = pref[i++];
            } else {
                temp[k++] = pref[j++];
            }
        }
        
        while (i <= mid) {
            temp[k++] = pref[i++];
        }
        
        while (j <= right) {
            temp[k++] = pref[j++];
        }
        
        for (int p = left; p <= right; ++p) {
            pref[p] = temp[p];
        }
        return cnt;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> pref(n+1, 0);
        for(int i = 0; i < n; i++) pref[i+1] = pref[i] + nums[i];
        vector<long long> temp(n+1, 0);
        return solve(pref, temp, 0, n, lower, upper);
    }
};