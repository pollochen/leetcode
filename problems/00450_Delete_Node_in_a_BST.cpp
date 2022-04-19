/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
// Runtime: 39 ms, faster than 72.25% of C++ online submissions for Delete Node in a BST.
// Memory Usage: 32.8 MB, less than 31.84% of C++ online submissions for Delete Node in a BST.
class Solution {
private:
    TreeNode *find_min(TreeNode *root)
    {
        while (root != NULL && root->left != NULL) {
            root = root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                // left is NULL
                TreeNode *tmp = root->right;
                delete root;
                return tmp;
            } else if (root->right == NULL) {
                // right is NULL
                TreeNode *tmp = root->left;
                delete root;
                return tmp;
            } else {
                // no NULL in children
                TreeNode *node = find_min(root->right);
                root->val = node->val;
                root->right = deleteNode(root->right, node->val);
            }
        }
        return root;
    }
};