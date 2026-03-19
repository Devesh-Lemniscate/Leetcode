/*
 * Problem 2385: Amount of Time for Binary Tree to Be Infected
 * Language: C++
 */
class Solution {
    int maxTime = 0;

    int traverse(TreeNode* root, int start) {
        if (!root) return 0;

        int leftVal = traverse(root->left, start);
        int rightVal = traverse(root->right, start);

        if (root->val == start) {
            maxTime = max(maxTime, max(leftVal, rightVal));
            return -1; 
        }

        if (leftVal >= 0 && rightVal >= 0) {
            return 1 + max(leftVal, rightVal);
        }

        int dist = abs(leftVal < 0 ? leftVal : rightVal);
        int oppHeight = leftVal < 0 ? rightVal : leftVal;

        maxTime = max(maxTime, dist + oppHeight);

        return -(dist + 1); 
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        maxTime = 0;
        traverse(root, start);
        return maxTime;
    }
};