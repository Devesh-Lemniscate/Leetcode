/*
 * Problem 1838: Frequency of the Most Frequent Element
 * Language: C++
 */
#define ll long long
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        ll i=0, j = 0, sum = 0, maxLen = 0;
        for (i = 0; i < nums.size(); i++){
            sum += nums[i];
            while ((i - j + 1) * nums[i] - sum > k){
                sum -= nums[j];
                j++;
            }
            maxLen = max(maxLen, i-j+1);
        }
        return maxLen;
    }
};