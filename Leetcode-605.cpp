class Solution {
    public:
        bool canPlaceFlowers(vector<int>& arr, int k) {
            int n = arr.size(), cnt = 0;
            if(n==1){
                if((k==1) && arr[0]==0)return true;
                else if(k==0) return true;
                else return false;
            }
            if(arr[0]==0 && arr[1]==0){
                arr[0] = 1;
                cnt++;
            }
            for(int i = 1; i < n-1; i++){
                if(arr[i-1]==0 && arr[i+1]==0 && arr[i]==0){
                    arr[i] = 1;
                    cnt++;
                } 
            }
            if(arr[n-1]==0 && arr[n-2] == 0) cnt++;
            return cnt>=k;
        }
    };