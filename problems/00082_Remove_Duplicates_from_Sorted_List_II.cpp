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

        ListNode *root = NULL;
        ListNode *node_prev = NULL;
        while (head != NULL) {
            if ((head->next != NULL) && (head->val == head->next->val)){
                int val = head->val;
                // step to node with different value
                while (head != NULL) {
                    if (head->val != val) {
                        break;
                    } else {
                        head = head->next;
                    }
                }
                if ((head == NULL) && (node_prev != NULL)) {
                    node_prev->next = NULL;
                }
            } else {
                if (root == NULL) {
                    root = head;
                    node_prev = head;
                } else {
                    node_prev->next = head;
                    node_prev = head;
                }
                head = head->next;
            }
        }
        return root;
    }
};