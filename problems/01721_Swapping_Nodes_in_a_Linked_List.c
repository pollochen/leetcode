// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/discuss/1912205/C%2B%2B-two-pointer-approach
// 2 pointers
// Runtime: 236 ms, faster than 86.27% of C online submissions for Swapping Nodes in a Linked List.
// Memory Usage: 48.6 MB, less than 14.57% of C online submissions for Swapping Nodes in a Linked List.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode *left = head;
    struct ListNode *right = head;
    struct ListNode *cur = head;
    int count = 1;
    while (cur != NULL) {
        if (count < k) {
			// only step k for left pointer
            left = left->next;
        }
        if (count > k) {
			// delay k steps to start
            right = right->next;
        }
        
        count++;
        cur = cur->next;
    }
    
    // swap value only!!
    int tmp = left->val;
    left->val = right->val;
    right->val = tmp;
    return head;    
}