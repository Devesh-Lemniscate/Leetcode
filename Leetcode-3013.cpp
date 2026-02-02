/*
 * Problem 3013: Divide an Array Into Subarrays With Minimum Cost II (POTD)
 * Language: C++
 */
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long curr = 0;
        multiset<int> st1, st2;
        int need = k - 1;

        for (int i = 1; i <= dist + 1 && i < n; i++) {
            st1.insert(nums[i]);
            curr += nums[i];
            if (st1.size() > need) {
                auto it = prev(st1.end());
                curr -= *it;
                st2.insert(*it);
                st1.erase(it);
            }
        }

        long long ans = curr;

        for (int i = dist + 2; i < n; i++){
            int out = nums[i - dist - 1];
            int in = nums[i];

            auto iter = st1.find(out);
            if (iter != st1.end()) {
                st1.erase(iter);
                curr -= out;
            } else {
                auto it_r = st2.find(out);
                if(it_r != st2.end()) st2.erase(it_r);
            }
            if (st1.size() < need && !st2.empty()) {
                auto it = st2.begin();
                st1.insert(*it);
                curr += *it;
                st2.erase(it);
            }

            st1.insert(in);
            curr += in;
            if (st1.size() > need) {
                auto it = prev(st1.end());
                curr -= *it;
                st2.insert(*it);
                st1.erase(it);
            }

            ans = min(ans, curr);
        }

        return ans + nums[0];
    }
};