/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Runtime: 2 ms, faster than 87.47 % of C online submissions for Merge Two Sorted Lists.
// Memory Usage : 6.5 MB, less than 8.53 % of C online submissions for Merge Two Sorted Lists.
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	struct ListNode *node_cur = NULL;
	struct ListNode *node_root = NULL;
	if ((list1 == NULL) && (list2 == NULL)) {
		return NULL;
	}

	if (list1 == NULL) {
		return list2;
	}

	if (list2 == NULL) {
		return list1;
	}

	do {
		struct ListNode *node_new = (struct ListNode *)malloc(sizeof(struct ListNode));
		node_new->next = NULL;

		if (list1 == NULL) {
			// copy list 2
			node_new->val = list2->val;
			list2 = list2->next;
		} else if (list2 == NULL) {
			// copy list 1
			node_new->val = list1->val;
			list1 = list1->next;
		} else {
			// compare list 1 & 2
			if (list1->val <= list2->val) {
				node_new->val = list1->val;
				list1 = list1->next;
			} else {
				node_new->val = list2->val;
				list2 = list2->next;
			}
		}

		if (node_root == NULL) {
			// root node
			node_root = node_new;
			node_cur = node_new;
		} else {
			// child node, append
			node_cur->next = node_new;
			node_cur = node_new;
		}
	} while (list1 != NULL || list2 != NULL);

	return node_root;
}

// in-place merge
// Runtime: 4 ms, faster than 74.37% of C online submissions for Merge Two Sorted Lists.
// Memory Usage: 6.3 MB, less than 8.58% of C online submissions for Merge Two Sorted Lists.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head;
    struct ListNode *result;
    if (list1 == NULL && list2 == NULL) return NULL; // all NULL, return NULL
    // one NULL, return the other one
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    // check head node
    if (list1->val < list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }
    // save root node
    result = head;
    // start to chain nodes
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            // next is list1
            head->next = list1;
            list1 = list1->next;
        } else {
            // next is list2
            head->next = list2;
            list2 = list2->next;
        }
        // step head
        head = head->next;
    }
    // append non-NULL list to head
    if (list1 != NULL) head->next = list1;
    if (list2 != NULL) head->next = list2;
    return result;
