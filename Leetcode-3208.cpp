class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& arr, int k) {
            int n = arr.size();
            int j=0, cnt = 0;
            for(int i = 0; i < n+k-1; i++){
                if(i>0 && arr[i%n]==arr[(i-1)%n]) j = i;
                if(i-j+1>=k)cnt++;
            }
            return cnt;
        }
    };