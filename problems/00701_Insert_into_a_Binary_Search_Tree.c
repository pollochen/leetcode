/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// recursion
// Runtime: 44 ms, faster than 95.24% of C online submissions for Insert into a Binary Search Tree.
// Memory Usage: 22.8 MB, less than 21.09% of C online submissions for Insert into a Binary Search Tree.
void insert_x(struct TreeNode* root, int val){

    struct TreeNode *node;

    if (val > root->val) {
        if (root->right == NULL) {
            node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            node->val = val;
            node->right = NULL;
            node->left = NULL;
            root->right = node;
            return;
        } else {
            insert_x(root->right, val);
        }
    } else {
        if (root->left == NULL) {
            node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            node->val = val;
            node->right = NULL;
            node->left = NULL;
            root->left = node;
            return;
        } else {
            insert_x(root->left, val);
        }
    }
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if (root == NULL) {
        struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->right = NULL;
        node->left = NULL;
        root = node;
    } else {
        insert_x(root, val);
    }
    return root;
}

// interation
// Runtime: 65 ms, faster than 57.82% of C online submissions for Insert into a Binary Search Tree.
// Memory Usage: 22.8 MB, less than 44.90% of C online submissions for Insert into a Binary Search Tree.
void insert_iter(struct TreeNode* root, int val){
    struct TreeNode* node;
    while (1) {
        if (val > root->val) {
            if (root->right == NULL) {
                node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                node->right = NULL;
                node->left = NULL;
                node->val = val;
                root->right = node;
                return;
            } else {
                root = root->right;
            }
        } else {
            if (root->left == NULL) {
                node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                node->right = NULL;
                node->left = NULL;
                node->val = val;
                root->left = node;
                return;
            } else {
                root = root->left;
            }
        }
    }
}
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if (root == NULL) {
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->right = NULL;
        node->left = NULL;
        node->val = val;
        root = node;
    } else {
        insert_iter(root, val);
    }
    return root;
}