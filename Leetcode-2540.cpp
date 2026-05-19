/*
 * Problem 2540: Minimum Common Value (POTD)
 * Language: C++
 */
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if(len2 > len1) return getCommon(nums2, nums1);
        int j  = 0;
        for(int i = 0; i < len2 && j < len1; i++){
            while(j < len1 && nums1[j] < nums2[i]) j++;
            if(j < len1 && nums2[i] == nums1[j]) return nums2[i];
        }
        return -1;
    }
};