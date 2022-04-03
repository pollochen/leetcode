/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// brute force (put node into result if it's prev and next value is not the same.
// Runtime: 0 ms, faster than 100.00% of C online submissions for Remove Duplicates from Sorted List II.
// Memory Usage: 6.4 MB, less than 49.30% of C online submissions for Remove Duplicates from Sorted List II.
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    result->next = NULL;
    if (head == NULL) return NULL;
    int cur = INT_MAX;
    struct ListNode *node = result;
    struct ListNode *prev = NULL;
    int val;
    struct ListNode *next = NULL;
    while (head != NULL) {
        val = head->val;
        next = head->next;
        if ((prev == NULL || (prev!= NULL && prev->val != val)) && (next == NULL || (next != NULL && next->val != val))) {
            node->next = head;
            node = node->next;
        }
        prev = head;
        head = head->next;
        node->next = NULL; // must set node->next to NULL here
    }
    return result->next;
}