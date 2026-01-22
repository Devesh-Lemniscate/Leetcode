/*
 * Problem 3507: Minimum Pair Removal to Sort Array I (POTD)
 * Language: C++
 */
class Solution {
public:
    bool check(vector<int> &nums, int j){
        for(int i = 0; i < j-1; i++){
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
    
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int j = n;
        if(check(nums, j)) return 0;
        int cnt = 0;
        
        while(j > 1){
            int idx = 0, mn = nums[0] + nums[1];
            for(int i = 1; i < j-1; i++){
                if(nums[i] + nums[i+1] < mn){
                    mn = nums[i] + nums[i+1];
                    idx = i;
                }
            }
            nums[idx] += nums[idx+1];
            for(int i = idx+1; i < j-1; i++){
                nums[i] = nums[i+1];
            }
            j--;
            cnt++;
            if(check(nums, j)) return cnt;
        }
        
        if(check(nums, j)) return cnt;
        else return cnt+1;
    }
};
