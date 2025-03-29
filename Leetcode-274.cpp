class Solution {
    public:
        int hIndex(vector<int>& a) {
            vector<int> arr(a.size()+1, 0);
            for(auto ele: a){
                if(ele>a.size())arr[a.size()]++;
                else arr[ele]++;
            }
            int ans = 0;
            for(int i = a.size(); i >=0; i--){
                ans+=arr[i];
                if(ans>=i)return i;
            }
            return 0;
        }
    };