class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int> arr(1000001, 1);
            arr[0] = 0; arr[1] = 0;
            for(int i = 2; i < 1000001; i++){
                if(arr[i]==1){
                    for(int j = i+i; j < 1000001; j+=i){
                        arr[j] = 0;
                    }
                }
            }
            int mn = INT_MAX, a = -1, b = -1, mina = -1, minb=-1;
            for(int i = left; i <=right; i++){
                if(arr[i]){
                    b=a; a=i;
                    if(minb==-1 || (a-b) < (minb-mina)){
                        mina = b;
                        minb = a;
                        if(minb-mina < 3)break;
                    } 
                }
            }
            if(mina==-1)minb=-1;
            return {mina, minb};
        }
    };