// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow;
        slow = head;
        unordered_set<ListNode*> set;

        while ( true ) {
            if ( set.find(slow) != set.end() ) {
                return slow;
            } 
            if ( slow == NULL ) return NULL;
            set.insert(slow);
            slow = slow->next;
        }
    }
};