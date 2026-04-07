/*
 * Problem 234: Palindrome Linked List
 * Language: C++
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head){
        ListNode* curr = head, *prev = NULL;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next=prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        temp = reverse(temp);
        while(temp && head){
            if(temp->val != head->val) return false;
            temp = temp->next;
            head = head->next;
        }
        return true;
    }
};