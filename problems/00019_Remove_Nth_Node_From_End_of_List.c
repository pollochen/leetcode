/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
		// get length
		struct ListNode *x = head;
		struct ListNode *result = head;
		int length = 0;
		int count;
		while (x != NULL) {
			x = x->next;
			length++;
		}
		if (n < length) {
			x = head;
			count = length - n -1;
			while (count > 0) {
				x = x->next;
				count--;
			}
			x->next = x->next->next;
		} else {
			// remove first element
			result = result->next;
		}
		return result;
}