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
        ListNode* findMid(ListNode* head){
            ListNode *slow = head, *fast = head->next;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
        ListNode* helper(ListNode* head1, ListNode* head2){
            ListNode* head = new ListNode(0);
            ListNode* temp = head;
            while(head1 && head2){
                if(head1->val > head2->val){
                    temp->next = head2;
                    head2 = head2->next;
                }else{
                    temp->next = head1;
                    head1 = head1->next;
                }
                temp = temp->next;
            }
            if(head1)temp->next = head1;
            else temp->next = head2;
            return head->next;
        }
        ListNode* merge(ListNode* head){
            if(head==NULL || head->next==NULL) return head;
            ListNode* mid = findMid(head);
            ListNode* left = head, *right = mid->next;
            mid->next = NULL;
            left = merge(left);
            right = merge(right);
            return helper(left, right);
        }
        ListNode* insertionSortList(ListNode* head) {
            head = merge(head);
            return head;
        }
    };