/*
 * Problem 1352: Product of the Last K Numbers (POTD)
 * Language: C++
 */
class ProductOfNumbers {
public:
    vector<long long> ans;
    int p = 1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            ans.clear();
            p=1;
        }else{
            p*=num;
            ans.push_back(p);
        }
    }
    
    int getProduct(int k) {
        int n = ans.size();
        if(n<k) return 0;
        if(n==k) return ans[n-1];
        return ans[n-1]/ans[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */