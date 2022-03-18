// Runtime: 3 ms, faster than 95.33% of C++ online submissions for Partition List.
// Memory Usage: 10.4 MB, less than 33.13% of C++ online submissions for Partition List.
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode root_smaller(0);
		ListNode root_larger(0);
		ListNode* cur = head;
		ListNode* s = &root_smaller;
		ListNode* l = &root_larger;
		ListNode* prev;
		while (cur != NULL) {
			prev = cur;
			cur = cur->next;
			if (prev->val < x) {
				// chain this node to smaller list
				s->next = prev;
				s = prev;
				s->next = NULL;
			} else {
				// chain this node to larger list
				l->next = prev;
				l = prev;
				l->next = NULL;
			}
		}
		// chain larger list to last of smaller list
		s->next = root_larger.next;
		// return head of smaller list
		return root_smaller.next;
	}
};

void test_00086_Partition_List(void)
{
	Solution s;
	ListNode* root = make_list_node(vector<int>{1, 4, 3, 2, 5, 2});
	print_node_list(root);
	print_node_list(s.partition(root, 3));

	ListNode* root2 = make_list_node(vector<int>{2, 1});
	print_node_list(root2);
	print_node_list(s.partition(root2, 2));

	ListNode* root3 = make_list_node(vector<int>{2});
	print_node_list(root3);
	print_node_list(s.partition(root3, 1));

	ListNode* root4 = make_list_node(vector<int>{2});
	print_node_list(root4);
	print_node_list(s.partition(root4, 2));

	print_node_list(NULL);
	print_node_list(s.partition(NULL, 2));

}