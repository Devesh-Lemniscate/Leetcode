/*
 * Problem 1577: Number of Ways Where Square of Number Is Equal to Product of Two Numbers
 * Language: C++
 */
#define ll long long
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<ll, int> mp1, mp2;
        for(int i = 0; i < n; i++) mp1[nums1[i]]++;
        for(int i = 0; i < m; i++) mp2[nums2[i]]++;
        
        ll cnt = 0;

        for(int i = 0; i < n; i++){
            ll num = 1LL * nums1[i] * nums1[i];
            for(int j = 0; j < m; j++){
                if((num % nums2[j]) == 0){
                    ll needed = num / nums2[j];
                    if(needed == nums2[j]) cnt += mp2[needed] - 1;
                    else if(mp2.count(needed)) cnt += mp2[needed];
                }
            }
        }

        for(int i = 0; i < m; i++){
            ll num = 1LL * nums2[i] * nums2[i];
            for(int j = 0; j < n; j++){
                if((num % nums1[j]) == 0){
                    ll needed = num / nums1[j];
                    if(needed == nums1[j]) cnt += mp1[needed] - 1;
                    else if(mp1.count(needed)) cnt += mp1[needed];
                }
            }
        }

        return cnt / 2;
    }
};