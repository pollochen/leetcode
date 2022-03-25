/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if (head == NULL) return NULL;
    struct ListNode *result = head;
    struct ListNode *prev = NULL;
    
    // remove first nodes with val
    while ((head != NULL) && (head->val == val)) {
        head = head->next;
    }
    
    result = head;
    prev = head;
    // remove nodes inside list
    while (head != NULL) {
        if (head->val == val) {
            prev->next = head->next;
        } else {
            prev = head;
        }
        head = head->next;
    }
    return result;
}

// Runtime: 14 ms, faster than 66.32% of C online submissions for Remove Linked List Elements.
// Memory Usage: 8.2 MB, less than 28.65% of C online submissions for Remove Linked List Elements.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val){
    if (head == NULL) return NULL;

    struct ListNode *n_prev = NULL;
    struct ListNode *result = head;
    while (head != NULL) {
        if (head->val == val) {
            // remove this node
            if (n_prev == NULL) {
                // it is first node
                result = head->next;
            } else {
                // it is middle node
                n_prev->next = head->next;
            }
        } else {
            // keep this node, set previous node as this node
            n_prev = head;
        }
        head = head->next;
    }
    return result;
}