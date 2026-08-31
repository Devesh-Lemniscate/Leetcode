/*
 * Problem 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points (POTD)
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* current = head;
        if(!head || !head->next || !head->next->next) return {-1, -1};
        ListNode* prev = head;
        current = current->next;
        int index = 0, firstCritical = -1, prevCritical = -1;
        int minDistance = INT_MAX, maxDistance = INT_MIN;
        while(current->next){
            if((prev->val < current->val && current->next->val < current->val) || (prev->val > current->val && current->next->val > current->val)){
                if(firstCritical == -1){
                    firstCritical = index;
                    prevCritical = index;
                }
                else{
                    minDistance = min(minDistance, index - prevCritical);
                    maxDistance = index - firstCritical;
                    prevCritical = index;
                }
            }
            prev = current;
            current = current->next;
            index++;
        }

        if(maxDistance == INT_MIN || minDistance == INT_MAX) return {-1, -1};
        else return {minDistance, maxDistance};
    }
};