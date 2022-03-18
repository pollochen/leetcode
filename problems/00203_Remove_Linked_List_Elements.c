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
