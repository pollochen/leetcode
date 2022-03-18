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
        if (head == NULL) return head;

        int val_cur = head->val;
        ListNode *root = head;
        ListNode *node_cur = head;
        while (head != NULL) {
            if (head->val != val_cur) {
                // new different node
                if (node_cur->next != head) {
                    node_cur->next = head;
                }

                val_cur = head->val;
                node_cur = head;
            } else {
                // same value node, skip it
                if (head->next == NULL) {
                    node_cur->next = NULL;
                }
            }
            head = head->next;
        }
        return root;
    }
};