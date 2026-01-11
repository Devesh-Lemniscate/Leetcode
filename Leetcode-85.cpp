/*
 * Problem 85: Maximal Rectangle (POTD)
 * Language: C++
 */
class Solution {
public:

int help(vector < int > &v) {
	stack <int> st;
	int maxA = 0;
	int n = v.size();
	for (int i = 0; i <= n; i++) {
		while (!st.empty() && (i == n || v[st.top()] >= v[i])) {
			int height = v[st.top()];
			st.pop();
			int width;
			if (st.empty())	width = i;
			else width = i - st.top() - 1;
			maxA = max(maxA, width * height);
		}
		st.push(i);
	}
	return maxA;
}

int solve(vector<vector<char>>&v, int n, int m) {
	int maxArea = 0;
	vector<int> height(m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '1') height[j]++;
			else height[j] = 0;
		}
		int area = help(height);
		maxArea = max(area, maxArea);
	}

	return maxArea;
}


    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = solve(matrix, n, m);
        return ans;
    }
};