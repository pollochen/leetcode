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
    ListNode* reverseList(ListNode* head) {
        ListNode *n_prev = NULL;
        ListNode *result = NULL;

        while (head != NULL) {
            ListNode *tmp = head->next;
            if (tmp == NULL) result = head;

            head->next = n_prev;
            n_prev = head;
            head = tmp;
        }
        return result;
    }
};