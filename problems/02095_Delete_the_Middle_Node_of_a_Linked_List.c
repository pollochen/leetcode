/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteMiddle(struct ListNode* head){
		struct ListNode *slow = head;
		struct ListNode *fast = head;
		struct ListNode *pre = NULL;
		if (head->next == NULL) { return NULL; } // one node
		if (head->next->next == NULL) { 
			// 2 nodes
			head->next = NULL;
			return head;
		}
		while (fast != NULL && fast->next != NULL) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		
		pre->next = pre->next->next;

		return head;
}