class Solution {
    public:
        int minimumBoxes(vector<int>& apple, vector<int>& arr) {
            sort(arr.rbegin(), arr.rend());
            int sum = accumulate(apple.begin(), apple.end(), 0);
            int ans = 0;
            for(int i = 0; i < arr.size(); i++){
                sum-=arr[i];
                if(sum<=0){
                    ans = i;
                    break;
                }
            }
            return ans+1;
        }
    };