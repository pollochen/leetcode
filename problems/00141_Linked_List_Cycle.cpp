/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
		if (head == NULL) return false;
		ListNode *a_1 = head;
		ListNode *a_2 = head;
		while (a_1 != NULL && a_2 != NULL) {
			if (a_1->next != NULL) a_1 = a_1->next;
			else a_1 = NULL;

			if (a_2->next != NULL) {
				if (a_2->next->next != NULL) {
					a_2 = a_2->next->next;
				} else a_2 = NULL;
			} else a_2 = NULL;
			if ((a_2 == a_1) && (a_1 != NULL)) return true;
		}
		return false;        
    }
};

// fast slow pointers
// Runtime: 10 ms, faster than 84.53% of C++ online submissions for Linked List Cycle.
// Memory Usage: 8.1 MB, less than 57.19% of C++ online submissions for Linked List Cycle.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ((head == NULL) || (head->next == NULL)) {
            return false;
        }
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while (fast != NULL) {
            if (fast->next == NULL) return false;
            if (fast == slow) return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};