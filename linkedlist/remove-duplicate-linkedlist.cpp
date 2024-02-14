// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = new ListNode(101);
        dummy->next = head;

        ListNode* temp = dummy;


        while ( temp->next != NULL ) {
            int ele = 101;
            while ( temp->next && temp->next->next && temp->next->val == temp->next->next->val ) {
                ele = temp->next->val;
                temp->next = temp->next->next;
            }

            while ( temp->next && ele == temp->next->val ) {
                temp->next = temp->next->next;
            }
            if ( ele == 101 ) temp = temp->next;
        }

        return dummy->next;
    }
};