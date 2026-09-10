/*
 * Problem 2265: Count Nodes Equal to Average of Subtree (POTD)
 * Language: C++
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int ans = 0;
    pair<int, int> helper(TreeNode* root){
        if(!root) return {0, 0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        int lc = left.first, rc = right.first;
        int ls = left.second, rs = right.second;
        int sum = ls + rs + root->val;
        int count = lc + rc + 1;
        if(sum / count == root->val) ans++;
        return {count, sum};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};