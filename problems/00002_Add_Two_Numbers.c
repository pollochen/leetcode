/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

	struct ListNode *node_root = NULL;
	struct ListNode *node_cur  = NULL;

	int flag_carry = 0;
	while ((l1 != NULL) || (l2 != NULL)) {
		int val_1 = 0;
		int val_2 = 0;
		if (l1 != NULL) val_1 = l1->val;
		if (l2 != NULL) val_2 = l2->val;

		int val = val_1 + val_2 + flag_carry;
		flag_carry = 0;

		if (val >= 10) {
			flag_carry = 1;
			val -= 10;
		}

		// create a new node
		struct ListNode *node_new = (struct ListNode *)malloc(sizeof(struct ListNode));
		node_new->next = NULL;
		node_new->val = val;

		if (node_root == NULL) {
			// no root node, hook it
			node_root = node_new;
		} else {
			// hook to current node
			node_cur->next = node_new;
		}

		node_cur = node_new;

		if (l1 != NULL) l1 = l1->next;
		if (l2 != NULL) l2 = l2->next;
	}

	if (flag_carry == 1) {
		// create a new node
		struct ListNode *node_new = (struct ListNode *)malloc(sizeof(struct ListNode));
		node_new->next = NULL;
		node_new->val = 1;
		node_cur->next = node_new;
	}
	return node_root;
}