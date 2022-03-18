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
	ListNode* reverseList(ListNode* head) {
		ListNode *n_prev = NULL;
		ListNode *result = NULL;

		while (head != NULL) {
			ListNode *tmp = head->next;
			if (tmp == NULL) result = head;

			head->next = n_prev;
			n_prev = head;
			head = tmp;
		}
		return result;
	}

ListNode* reverseEvenLengthGroups(ListNode* head) {
		if (head == NULL) return NULL;
		int target = 1;
		int count = 0;
		ListNode *result = head;
		ListNode *left = NULL;
		ListNode *right = NULL;
		ListNode *node_pre = NULL;
		ListNode *list_head = NULL;
		ListNode *list_tail = NULL;
		while (head != NULL) {
			count++;
			if (count == 1) {
				left = head;
				list_head = node_pre;
			}
			if (count == target) {
				right = head;
				if ((target % 2) == 0) {
					list_head->next = NULL;
					list_tail = right->next;
					right->next = NULL;

					// reverse
					ListNode *rl = reverseList(left);

					// re-chain
					list_head->next = rl;
					left->next = list_tail;
					head = left;
				}

				count = 0;
				target += 1;
			}

			node_pre = head;
			head = head->next;
		}

		// check last group length
		if ((count != 0) && ((count % 2) == 0)) {
			ListNode *rl = reverseList(left);
			list_head->next = rl;
		}
		return result;
	}
};