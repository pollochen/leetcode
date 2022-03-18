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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            return new TreeNode(head->val);
        }

        ListNode *mid = get_mid_node(head);
        TreeNode *n = new TreeNode(mid->val);
        if (mid != head) n->left  = sortedListToBST(head);
        n->right = sortedListToBST(mid->next);
        return n;
    }
};