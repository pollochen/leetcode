/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// https://ithelp.ithome.com.tw/articles/10223721
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		if (head == NULL) return NULL;
        if (head->next != NULL) {
            if (head->next->next != NULL) {
                if (head->next->next == head) return head;
            }
        }
		ListNode *a1 = head;
		ListNode *a2 = head;
		while (a2 != NULL && a1 != NULL && a1->next != NULL && a2->next != NULL) {
            a1 = a1->next;
            a2 = a2->next->next;
			if (a1 == a2) {
                // found
                a1 = head;
                a2 = a2;
                while (a1 != a2) {
                    a1 = a1->next;
                    a2 = a2->next;
                }
                return a2;
            }
		}
		return NULL;
    }
};