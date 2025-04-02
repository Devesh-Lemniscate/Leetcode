class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans = 0;
            int maxNum = 0, maxPair = 0;
            for(auto num: nums){
                ans = max(ans, 1LL*maxPair*num);
                maxPair = max(maxPair, maxNum-num);
                maxNum = max(maxNum, num);
            }
            return ans;
        }
    };