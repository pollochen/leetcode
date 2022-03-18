/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int get_ll_length(struct ListNode* head)
{
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

bool isPalindrome(struct ListNode* head){
    int length = get_ll_length(head);
    struct ListNode *list1 = head;
    struct ListNode *list2 = NULL;
    int count = 0;

    if (length == 1) return true;

    while ((head != NULL) && (count < ((length / 2) - 1))) {
        count++;
        head = head->next;
    }

    struct ListNode *n_start = head->next;
    struct ListNode *n_prev = NULL;
    head->next = NULL;

    // reverse n_start
    while (n_start != NULL) {
        struct ListNode *tmp = n_start->next;
        if (n_start->next == NULL) { list2 = n_start; }
        n_start->next = n_prev;
        n_prev = n_start;
        n_start = tmp;
    }

    while (list1 != NULL) {
        if (list1->val != list2->val) {return false; }
        list1 = list1->next;
        list2 = list2->next;
    }
    return true;
}