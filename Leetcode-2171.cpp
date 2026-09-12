/*
 * Problem 2171: Removing Minimum Number of Magic Beans
 * Language: C++
 */
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n =  beans.size();
        long long mini = LLONG_MAX;
        long long sum = accumulate(beans.begin(), beans.end(), 0LL);
        long long curr = 0;
        for(int i = 0; i < n; i++){
            mini = min(mini, sum - (1LL * (n-i)* beans[i]));
            curr += beans[i];
        }
        return mini;
    }
};