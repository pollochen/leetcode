// https://www.cnblogs.com/grandyang/p/4261431.html
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
	Node* copyRandomList(Node* head) {
		Node *cur = head;
		Node *new_head = NULL;
		Node *new_cur = NULL;
		unordered_map<Node *, Node *> m;

		if (head == NULL) return NULL;

		while (cur != NULL) {
			Node *node_new = new Node(cur->val);
			if (new_head == NULL) {
				new_head = node_new;
				new_cur = node_new;
			} else {
				new_cur->next = node_new;
                new_cur = node_new;
			}
			// build cur node -> new node map
			m[cur] = node_new;
			cur = cur->next;
		}

		new_cur = new_head;
		cur = head;
		while (new_cur != NULL) {
			if (cur->random != NULL) {
				// get the new node from cur node map
				Node *node_x = m[cur->random];
				new_cur->random = node_x;
			}
			new_cur = new_cur->next;
			cur = cur->next;
		}
		return new_head;
	}
};