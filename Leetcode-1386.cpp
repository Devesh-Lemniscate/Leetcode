/*
 * Problem 1386: Cinema Seat Allocation (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int m = reservedSeats.size();
        int count = 0, rows = 0;
        for(int i = 0; i < m; i++){
            unordered_set<int> st;
            while(i+1 < m && reservedSeats[i][0] == reservedSeats[i+1][0]){
                int row = reservedSeats[i][0], col = reservedSeats[i][1];
                st.insert(col);
                i++;
            }
            st.insert(reservedSeats[i][1]);
            if(!st.count(2) && !st.count(3) && !st.count(4) && !st.count(5)){
                st.insert(2); st.insert(3); st.insert(4); st.insert(5);
                count++;
            }
            if(!st.count(4) && !st.count(5) && !st.count(6) && !st.count(7)){
                st.insert(6); st.insert(7); st.insert(4); st.insert(5);
                count++;
            }
            if(!st.count(6) && !st.count(7) && !st.count(8) && !st.count(9)){
                st.insert(6); st.insert(7); st.insert(8); st.insert(9);
                count++;
            }
            rows++;
        }
        return count + (n-rows)*2;
    }
};