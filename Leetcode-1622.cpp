/*
 * Problem 1622: Fancy Sequence (POTD)
 * Language: C++
 */
class Fancy {
private:
    const int mod = 1e9+7;
    long long add = 0, mul = 1;
    vector<long long> nums;
    long long power(long long base, long long exp){
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n){
        return power(n, mod-2);
    }
public:
    Fancy() {
        
    }
    
    void append(int val) {
        nums.push_back((((val - add + mod) % mod) * (modInverse(mul) % mod)) % mod);
    }
    
    void addAll(int inc) {
        add = (add + inc) % mod;
    }
    
    void multAll(int m) {
        add = (add * m) % mod;
        mul = (mul * m) % mod;
    }
    
    int getIndex(int idx) {
        if(idx >= nums.size()) return -1;
        else return (1LL * mul * nums[idx] + add) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */