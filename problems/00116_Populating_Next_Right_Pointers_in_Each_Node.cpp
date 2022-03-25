// https://www.cnblogs.com/grandyang/p/4288151.html
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) return NULL;
		if (root->left != NULL) {
            root->left->next = root->right;  
    		if (root->next != NULL) root->right->next = root->next->left;
        } 
		if (root->left) connect(root->left);
		if (root->right) connect(root->right);
		return root;
	}
};

// BFS
// Runtime: 26 ms, faster than 56.08% of C++ online submissions for Populating Next Right Pointers in Each Node.
// Memory Usage: 17.1 MB, less than 37.18% of C++ online submissions for Populating Next Right Pointers in Each Node.
class Solution {
public:
    Node* connect(Node* root) {
        Node *node;
        Node *node_prev;
        queue<Node *> que;

        if (root == NULL) return NULL;

        que.push(root);
        while (que.empty() == false) {
            int size = que.size();
            node_prev = NULL;
            for (int i = 0; i < size; i++) {
                node = que.front(); que.pop();
                // chain next of previous node to this node
                if (node_prev != NULL) {
                    node_prev->next = node;
                }
                // push child nodes into queue
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
                // set previous node as this node
                node_prev = node;
            }
        }
        return root;
    }
};