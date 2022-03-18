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
    ListNode *get_mid_node(ListNode *head) {
        ListNode *n_mid_prev = NULL;
        while (head != NULL && head->next != NULL) {
            if (n_mid_prev == NULL) {
                n_mid_prev = head;
            } else {
                n_mid_prev = n_mid_prev->next;
            }
            head = head->next->next;
        }

        ListNode *n_mid = n_mid_prev->next;
        n_mid_prev->next = NULL;
        return n_mid;
    }

    ListNode* merge_list(ListNode* list1, ListNode* list2) {
        ListNode  dummy_node(0);
        ListNode *node_cur = &dummy_node;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                node_cur->next = list1;
                list1 = list1->next;
            } else {
                node_cur->next = list2;
                list2 = list2->next;
            }
            node_cur = node_cur->next;
        }
        if (list1 != NULL) node_cur->next = list1;
        else node_cur->next = list2;
        return dummy_node.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *n_mid = get_mid_node(head);
        ListNode *n_left =  sortList(head);
        ListNode *n_right = sortList(n_mid);
        return merge_list(n_left, n_right);
    }
};