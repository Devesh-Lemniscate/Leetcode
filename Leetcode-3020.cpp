/*
 * Problem 3020: Find the Maximum Number of Elements in Subset (POTD)
 * Language: C++
 */
class Solution {
private:
    long long find(long long num, vector<int> &nums, unordered_map<long long, long long> &freq){
        long long len = 0;
        long long curr = num;
        while(freq[curr] > 1){
            curr = curr * curr;
            len++;
        }
        if(freq[curr] == 1) return 2*len+1; 
        return 2*len-1;
    }
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, long long> freq;
        for(auto num: nums) freq[num]++;
        long long maxi = 0;
        if(freq.count(1)) maxi = freq[1];
        if(maxi % 2 == 0) maxi--;
        sort(nums.begin(), nums.end());
        for(long long i = 0; i < nums.size(); i++){
            if(nums[i] != 1){
                maxi = max(maxi, find(nums[i], nums, freq));
            }
        }
        return maxi;
    }
};