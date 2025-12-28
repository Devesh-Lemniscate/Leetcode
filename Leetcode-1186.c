/*
 * Problem 1186: Maximum Subarray Sum with One Deletion
 * Language: C
*/
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        int take = max(arr[0], arr[1]);
        int notTake = max(arr[0]+arr[1], arr[1]);
        int ans = max(take, notTake);
        for(int i = 2; i < arr.size(); i++){
            take = max(notTake, arr[i]+take);
            notTake = max(notTake+arr[i], arr[i]);
            ans = max(ans, max(take, notTake));
        }
        return ans;
    }
};
