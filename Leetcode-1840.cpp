/*
 * Problem 1840: Maximum Building Height (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.insert(restrictions.begin(), {1, 0});
        sort(restrictions.begin(), restrictions.end());
        int len = restrictions.size();
        for(int i = 1; i < len; i++){
            int difference = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1]+difference); 
        }
        for(int i = len-2; i >= 0; i--){
            int difference = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + difference);  
        }
        int maxHeight = 0;
        for(int i = 1; i < len; i++){
            int id1 = restrictions[i-1][0];
            int height1 = restrictions[i-1][1];

            int id2 = restrictions[i][0];
            int height2 = restrictions[i][1];

            int difference = id2 - id1;
            maxHeight = max(maxHeight, (height1 + height2 + difference) / 2);    
        }
        int id = restrictions[len-1][0];
        int height = restrictions[len-1][1];  

        maxHeight = max(maxHeight, height + (n-id));
        return maxHeight;
    }
};