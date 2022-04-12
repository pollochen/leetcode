/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// fast/slow pointer + reverse List 2 and merge 2 lists
// Runtime: 22 ms, faster than 64.21% of C online submissions for Reorder List.
// Memory Usage: 8.8 MB, less than 84.62% of C online submissions for Reorder List.

void reorderList(struct ListNode* head){
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode *tmp;
    struct ListNode *tmp1;
    struct ListNode *tmp2;
    
    if (head == NULL || head->next == NULL) return;   

    // use fast and slow to get center node
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *center;    
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        center = slow;
        slow = slow->next;
    }

    if (fast != NULL) {
        // if fast is not NULL, the center node should be slow
        // odd number
        center = slow;
        slow = slow->next; // start of List 2
    } else {
        // if fast is NULL, the center node should be previous node of slow
        // even number
    }

    // break head to List 1
    center->next = NULL;
    
    // reverse List 2
    l2 = NULL;
    while (slow != NULL) {
        tmp = slow->next;
        slow->next = l2;
        l2 = slow;
        slow = tmp;
    }
    
    // chain List 2 to List 1 with interleaving
    l1 = head;
    while (l1 != NULL && l2!= NULL) {
        tmp1 = l1->next;
        tmp2 = l2->next;
        l1->next = l2;
        l2->next = tmp1;
        l1 = tmp1;
        l2 = tmp2;
    }

    return;    
}