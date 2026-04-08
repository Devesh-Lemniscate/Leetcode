/*
 * Problem 138: Copy List with Random Pointer
 * Language: C++
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head, *dummy = new Node(-1);
        Node* newHead = dummy;
        while(temp){
            dummy->next = new Node(temp->val);
            dummy = dummy->next;
            mp[temp] = dummy;
            temp = temp->next;
        }
        temp = head;
        dummy = newHead->next;
        newHead = newHead->next;
        while(temp){
            newHead->random = mp[temp->random];
            temp = temp->next;
            newHead = newHead->next;
        }
        return dummy;
    }   
};