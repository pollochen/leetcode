/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Runtime: 5 ms, faster than 27.93 % of C online submissions for Remove Nth Node From End of List.
// Memory Usage : 6 MB, less than 29.25 % of C online submissions for Remove Nth Node From End of List.
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