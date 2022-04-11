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
// Runtime: 8 ms, faster than 75.93% of C++ online submissions for Remove Duplicates from Sorted List II.
// Memory Usage: 11.1 MB, less than 60.39% of C++ online submissions for Remove Duplicates from Sorted List II.
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