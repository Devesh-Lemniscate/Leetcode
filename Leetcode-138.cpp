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
        Node *temp = head;
        Node *dummy = new Node(10);
        Node *temp1 = dummy;
        // step 1 : deep copy without random pointer
        while(temp){
            Node *a = new Node(temp->val);
            temp1->next = a;
            temp = temp->next;
            temp1 = temp1->next;
        }
        // step 2 : create alternate connections 
        Node *dupli = dummy->next;
        Node *a = head, *b=dupli;
        dummy = new Node(-1);
        Node *tempD = dummy;
        while(a){
            tempD->next = a;
            a =a->next;
            tempD = tempD->next;
            tempD->next = b;
            b =b->next;
            tempD = tempD->next;
        }
        dummy = dummy->next;
        // step 3 : make alternate connections
        Node *t1 = dummy, *t2;
        while(t1){
            t2 = t1->next;
            if(t1->random) t2->random = t1->random->next;
            t1 = t1->next->next;
        }
        // step 4 : seperate connections
        Node * d1 = new Node(-1);
        Node * d2 = new Node(-1);
        t1=d1;
        t2=d2;
        Node *t = dummy;
        while(t){
            t1->next = t;
            t = t->next;
            t1 = t1->next;
            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1->next = NULL;
        t2->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;

    }
};