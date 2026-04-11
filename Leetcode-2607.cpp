/*
 * Problem 2607: Make K-Subarray Sums Equal
 * Language: C++
 */
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans = 0;
        k = __gcd(k, (int)arr.size()); 
        for(int i = 0; i < k; ++i){
            vector<int> v;
            for(int j = i; j < arr.size(); j += k) v.push_back(arr[j]); 
            sort(v.begin(), v.end());    
            int mn = v[v.size()/2];      
            for(int j = i; j < arr.size(); j += k) {
                ans += abs(mn - arr[j]); 
            }
        }
        
        return ans;
    }
};