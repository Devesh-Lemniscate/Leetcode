class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> smaller, larger, ans;
            int cnt = 0;
            for(auto ele: nums) {
                if(ele>pivot) larger.push_back(ele);
                else if(ele < pivot) smaller.push_back(ele);
                else cnt++;
            }
            ans = smaller;
            while(cnt--)ans.push_back(pivot);
            for(auto ele: larger)ans.push_back(ele);
            return ans;
        }
    };