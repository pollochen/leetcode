/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    // move val of next node
    // remove next node
    struct ListNode *n = node->next;
    node->val = n->val;
    node->next = n->next;
}