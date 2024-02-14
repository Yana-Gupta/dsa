// https://leetcode.com/problems/partition-list/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-101);
        dummy->next = head;
        ListNode* temp = dummy;
        ListNode* prev = new ListNode(-101);
        ListNode* p1 = prev;
        prev->next = head;

        while (prev != NULL && prev->next != NULL) {
            if (prev->next->val >= x) {
                prev = prev->next;
            } else {
                temp->next = prev->next;
                prev->next = prev->next->next;
                temp = temp->next;
            }
        }

        temp->next = p1->next;

        return dummy->next;
    }
};
