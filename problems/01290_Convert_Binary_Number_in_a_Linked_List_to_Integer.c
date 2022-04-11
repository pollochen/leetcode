/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Runtime: 0 ms, faster than 100.00% of C online submissions for Convert Binary Number in a Linked List to Integer.
// Memory Usage: 5.9 MB, less than 12.55% of C online submissions for Convert Binary Number in a Linked List to Integer.
int getDecimalValue(struct ListNode* head){
    long int result = 0;
    while (head != NULL) {
        result += head->val;
        result = result << 1;
        head = head->next;
    }
    return result >> 1;
}