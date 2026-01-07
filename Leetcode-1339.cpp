/*
 * Problem 1339: Maximum Product of Splitted Binary Tree (POTD)
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
    const long long mod = 1e9+7;
    vector<long long> subtree;
    long long total = 0;
    int helper(TreeNode* root){
        if(root == NULL) return 0;
        long long left = helper(root->left);
        long long right = helper(root->right);
        long long sum = root->val+left+right;
        subtree.push_back(sum);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        total = helper(root);
        long long ans = 0;
        for(auto it: subtree) ans = max(ans, it*(total-it));
        return ans % mod;
    }
};