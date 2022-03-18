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
    ListNode* middleNode(ListNode* head) {
        ListNode *n_fast = head;
        ListNode *n_slow = head;
        while (n_slow->next != NULL && n_fast->next != NULL && n_fast->next->next != NULL) {
            n_slow = n_slow->next;
            n_fast = n_fast->next->next;
        }
        if (n_fast->next == NULL) return n_slow;
        else return n_slow->next;
    }
};