/*
 * Problem 2948: Make Lexicographically Smallest Array by Swapping Elements (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> partitions;
        for(int i = 0; i < nums.size(); i++){
            partitions.push_back({nums[i], i});
        }
        sort(partitions.begin(), partitions.end());
        vector<vector<pair<int, int>>> components;

        for(int i = 0; i < nums.size(); ){
            vector<pair<int, int>> component;
            component.push_back({partitions[i].second, partitions[i].first});
            while (i + 1 < nums.size() && partitions[i+1].first-partitions[i].first <= limit) {
                i++;
                component.push_back({partitions[i].second, partitions[i].first});
            }
            i++; 
            sort(component.begin(), component.end());
            components.push_back(component);
        }
        vector<int> result(nums.size());
        int index = 0;
        for(auto component: components){
            for(auto it: component){
                int ind = it.first, val = partitions[index].first;
                result[ind] = val;
                index++;
            }
        }
        return result;
    }
};
