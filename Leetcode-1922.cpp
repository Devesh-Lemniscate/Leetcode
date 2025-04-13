#define MOD 1000000007
#define ll long long
class Solution {
private:
    ll calc(ll num, ll exp){
        ll ans = 1;
        while(exp){
            if(exp&1) ans = (ans*num)%MOD;
            num = (num*num)%MOD;
            exp/=2;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        ll even = (n+1)/2, odd = n/2;
        ll ans = (calc(5, even) * calc(4,odd))%MOD;
        return ans;      
    }
};