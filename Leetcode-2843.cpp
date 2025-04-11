class Solution {
    private:
        bool isValid(int num){
            string str = to_string(num);
            int len = str.size();
            if(len&1)return false;
            int sum = 0;
            for(int i = 0; i < len/2; i++){
                sum+=((str[i]-'0')-(str[len-i-1]-'0'));
            }
            return sum==0;
        }
    public:
        int countSymmetricIntegers(int low, int high) {
            int ans = 0;
            for(int i = low; i <= high; i++){
                if(isValid(i)) ans++;
            }
            return ans;
        }
    };