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
// brute force
// Runtime: 20 ms, faster than 56.12% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 11.4 MB, less than 72.68% of C++ online submissions for Reverse Nodes in k-Group.
class Solution {
public:
    int get_len(ListNode *head)
    {
        int len = 0;
        while (head != NULL) {
            head = head->next;
            len++;
        }
        return len;
    }
    
    ListNode *reverse(ListNode *x, ListNode *head, int k)
    {
        ListNode *prev = NULL;
        ListNode *last = head;
        ListNode *next;
        for (int i = 0; i < k; i++) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
		// return last node of reversed linked list
		// so we can chain it in next call
        x->next = prev;
        last->next = head;
        
        return last;
    }    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode dummy;
        
		// get length of linked list
        int len = get_len(head);
        
		// decide loop count
        int count = len / k;
        ListNode *prev = &dummy;

        for (int i = 0; i < count; i++) {
            prev = reverse(prev, head, k);
            head = prev->next;
        }
        return dummy.next;
    }
};