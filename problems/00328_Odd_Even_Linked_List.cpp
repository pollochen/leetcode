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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }
        ListNode *odd_head  = head->next->next;
        ListNode *even_head = head->next;
        ListNode *odd       = odd_head;
        ListNode *even      = even_head;
        ListNode *last_odd  = NULL;

        while (odd != NULL && even != NULL) {
            if (odd->next != NULL) {
                // next even is available
                even->next = odd->next;
                if (odd->next->next != NULL) {
                    // next odd is available
                    odd->next = odd->next->next;
                } else {
                    // next odd is not available
                    odd->next = NULL;
                }
            } else {
                // next even is not available, next odd would be not available also
                even->next = NULL;
            }
            even = even->next;
            last_odd = odd;
            odd  = odd->next;
        }

        //
        head->next = odd_head;
        // odd->last->next = even_head
        last_odd->next = even_head;
        return head;
    }
};