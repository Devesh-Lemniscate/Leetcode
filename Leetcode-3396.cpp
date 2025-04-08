class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            unordered_map<int, int> m;
            int idx = -1;
            for(int i = nums.size()-1; i >= 0; i--){
                m[nums[i]]++;
                if(m[nums[i]]==2){
                    idx = i;
                    break;
                }
            }
            if(idx==-1) return 0;
            return (idx+1)%3==0?(idx+1)/3:(idx+1)/3 + 1;
        }
    };