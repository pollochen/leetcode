


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Runtime: 7 ms, faster than 55.13% of C online submissions for Remove Duplicates from Sorted List.
// Memory Usage: 6.4 MB, less than 58.77% of C online submissions for Remove Duplicates from Sorted List.
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *n_prev = NULL;
    struct ListNode *result = head;
    while (head != NULL) {
        if (n_prev != NULL && n_prev->val == head->val) {
            // duplicate node
            // skip this node
            n_prev->next = head->next;
        } else {
            // normal case, set previous node as this node
            n_prev = head;
        }
        head = head->next;
    }
    return result;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/discuss/1877015/C%2B%2B-oror-100-faster-with-0-ms-Simplest-method-code
// Runtime: 8 ms, faster than 46.51% of C online submissions for Remove Duplicates from Sorted List.
// Memory Usage: 6.4 MB, less than 84.84% of C online submissions for Remove Duplicates from Sorted List.
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *result = head;
    if (head == NULL) return NULL;

    while (head->next != NULL) {
        if (head->val == head->next->val) {
            // duplicate node
            // skip this node and keep on this node
            head->next = head->next->next;
        } else {
            // step to next
            head = head->next;
        }
    }
    return result;
}