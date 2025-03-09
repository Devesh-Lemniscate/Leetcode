class Solution {
    public:
        int maxScore(vector<int>& arr, int k) {
            int n = arr.size();
            int left = 0, right = 0, maxSum = 0;
            for(int i = 0; i < k; i++){
                left+=arr[i];
            }
            maxSum = max(left, maxSum);
            for(int i = 0; i < k; i++){
                left-=arr[k-i-1];
                left+=arr[n-i-1];
                maxSum = max(maxSum, left);
            }
            return maxSum;
        }
    };