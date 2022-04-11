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
// BFS treaverse
// Runtime: 30 ms, faster than 11.75% of C++ online submissions for Populating Next Right Pointers in Each Node II.
// Memory Usage: 17.4 MB, less than 81.47% of C++ online submissions for Populating Next Right Pointers in Each Node II.
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
                if (node_prev != NULL) {
                    node_prev->next = node;
                }
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
                node_prev = node;
            }
        }
        return root;
    }
};