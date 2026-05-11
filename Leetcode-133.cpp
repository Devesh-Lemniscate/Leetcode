/*
 * Problem 133: Clone Graph
 * Language: C++
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node* org, Node* root, vector<Node*> &visited){
        visited[root->val] = root;
        for(auto node: org->neighbors){
            if(!visited[node->val]){
                Node* newNode = new Node(node->val);
                (root->neighbors).push_back(newNode);
                dfs(node, newNode, visited);
            }else (root->neighbors).push_back(visited[node->val]); 
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        vector<Node*> visited(101, NULL);
        Node *root = new Node(node->val);
        dfs(node, root, visited);
        return root;
    }
};