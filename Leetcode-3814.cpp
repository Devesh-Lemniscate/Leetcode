/*
 * Problem 3814: Maximum Capacity Within Budget
 * Language: C++
 */
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        
        vector<pair<int, int>> machines(n);
        for (int i = 0; i < n; i++) {
            machines[i] = {costs[i], capacity[i]};
        }
        sort(machines.begin(), machines.end());
        vector<int> prefixMax(n);
        prefixMax[0] = machines[0].second;
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], machines[i].second);
        }

        long long maxCap = 0;

        for (int i = 0; i < n; i++) {
            int currentCost = machines[i].first;
            int currentCap = machines[i].second;
            if (currentCost < budget) {
                maxCap = max(maxCap, (long long)currentCap);
            }
            int remainingBudget = budget - currentCost; 
            int targetPrice = remainingBudget - 1;

            if (targetPrice <= 0) continue; 

            auto it = upper_bound(machines.begin(), machines.end(), make_pair(targetPrice, 2000000000));
        
            int idx = distance(machines.begin(), it) - 1;

            int bestPartnerIdx = min(idx, i - 1);

            if (bestPartnerIdx >= 0) {
                maxCap = max(maxCap, (long long)currentCap + prefixMax[bestPartnerIdx]);
            }
        }

        return (int)maxCap;
    }
};