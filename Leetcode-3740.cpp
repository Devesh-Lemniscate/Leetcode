/*
 * Problem 3740: Minimum Distance Between Three Equal Elements I (POTD)
 * Language: C++
 */
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, queue<int>> mp;
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]].size() == 2){
                int curr = mp[nums[i]].front(); mp[nums[i]].pop();
                int dis = abs(i-curr) + abs(curr-mp[nums[i]].front()) + abs(i-mp[nums[i]].front());
                mini = min(mini, dis);
                mp[nums[i]].push(i);
            }else mp[nums[i]].push(i);
        }
        return mini == INT_MAX ? -1 : mini;
    }
};