/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void connect_dfs(struct Node *node)
{
    if (node == NULL) return;
    if (node->left != NULL) {
        // perfect binary tree has 2 leaves or none
        node->left->next = node->right; // left -> right
        if (node->next != NULL) {
            // right->next = right->parent->next->left
            node->right->next = node->next->left;
        }
        // go next nodes
        connect_dfs(node->left);
        connect_dfs(node->right);
    }
}

struct Node* connect(struct Node* root) {
	connect_dfs(root);
    return root;
}