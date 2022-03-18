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
class Solution {
public:
    int get_linkedlist_length(ListNode *head)
    {
        int ret = 0;
        while (head != NULL) {
            ret++;
            head = head->next;
        }
        return ret;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int len = get_linkedlist_length(head);
        k = k % len;

        if (k == 0) { return head; }

        ListNode *cur = head;
        // len = 5
        // k  = 2
        // step len = 5 - 2 - 1 = 2
        // step len - k - 1
        // step N nodes
        int steps = len - k - 1;
        for (int i = 0; i < steps; i++) {
            cur = cur->next;
        }

        // this node would be end node of new list
        // next node of this node will be start of new list
        ListNode *result = cur->next;
        cur->next = NULL;
        cur = result;
        // step to end of next node
        while (cur->next != NULL) {
            cur = cur->next;
        }
        // append start of old list to end of this node
        cur->next = head;
        return result;
    }
};