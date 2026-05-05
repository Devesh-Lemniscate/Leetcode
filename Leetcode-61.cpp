/*
 * Problem 61: Rotate List (POTD)
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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) return head;
        ListNode* first = head, *second = head, *prev = NULL;
        int count = 0;
        while(first){
            first = first->next;
            count++;
        }
        k = k % count;
        if(!k) return head;
        first = head;
        while(k-- && first){
            first = first->next;
        }
        while(first && first->next){
            prev = first;
            first = first->next;
            second = second->next;
        }
        ListNode* newHead = second->next;
        second->next = NULL;
        if(first)first->next = head;
        return newHead;
    }
};