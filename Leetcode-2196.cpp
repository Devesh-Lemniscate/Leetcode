/*
 * Problem 2196: Create Binary Tree From Descriptions (POTD)
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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;
        for(auto nodes: descriptions){
            int par = nodes[0], child = nodes[1], isLeft = nodes[2];
            if(mp.find(par) == mp.end()) mp[par] = new TreeNode(par);
            if(mp.find(child) == mp.end()) mp[child] = new TreeNode(child);
            if(isLeft == 1) mp[par]->left = mp[child];
            else mp[par]->right = mp[child];
            children.insert(child);
        }
        for(auto it: mp){
            if(children.find(it.first) == children.end()) return it.second;
        }
        return NULL;
    }
};