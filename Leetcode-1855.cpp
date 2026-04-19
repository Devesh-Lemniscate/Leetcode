/*
 * Problem 1855: Maximum Distance Between a Pair of Values (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0;
        for(int i = 0; i < nums1.size(); i++){
            int idx = upper_bound(nums2.begin() + i, nums2.end(), nums1[i], greater<int>()) - nums2.begin();
            idx--;
            if(idx >= i) maxi = max(maxi, idx - i);
        }
        return maxi;
    }
};