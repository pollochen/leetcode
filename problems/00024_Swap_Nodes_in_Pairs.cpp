// 26% faster version
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
// Runtime: 3 ms, faster than 69.71% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.6 MB, less than 6.94% of C++ online submissions for Swap Nodes in Pairs.
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *pre = new ListNode(0);
		ListNode *cur = head;
		ListNode *result = pre;
		pre->next = cur;
		while (cur != NULL) {
			if (cur->next != NULL) {
				// swap 
				ListNode *tmp = cur->next->next;
				pre->next = cur->next;
				cur->next->next = cur;
				cur->next = tmp;
			}
			pre = cur;
			cur = cur->next;			
		}
		return result->next;
	}
};

// Runtime: 3 ms, faster than 69.71% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.6 MB, less than 6.94% of C++ online submissions for Swap Nodes in Pairs.
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
	ListNode* swapPairs(ListNode* head) {
		ListNode *pre = new ListNode(0);
		ListNode *cur = head;
		ListNode *result = pre;
		pre->next = cur;
		while (cur != NULL && cur->next != NULL) {
            // swap 
            ListNode *tmp = cur->next->next;
            pre->next = cur->next;
            cur->next->next = cur;
            cur->next = tmp;
            // next step
			pre = cur;
			cur = cur->next;			
		}
		return result->next;
	}
};