// Runtime: 2 ms, faster than 84.27% of C online submissions for Reverse Linked List.
// Memory Usage: 6.3 MB, less than 85.11% of C online submissions for Reverse Linked List.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL;
    struct ListNode *tmp = NULL;
    while (head != NULL) {
        tmp = head->next;  // save next node
        head->next = prev; // assing next of current node to previous node
        prev = head;       // assign previous node as this node
        head = tmp;        // step current node
    }
    return prev;
}