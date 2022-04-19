// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* result;
    bool lca_dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL) {
            return false;
        }
        bool flag_left = lca_dfs(root->left, p, q); // find if p or q is in left node
        bool flag_center = 0;
        if ((root == p) || (root == q)) { // find if p or q is in this node
            flag_center = 1;
        }
        bool flag_right = lca_dfs(root->right, p, q); // find if p or q is in right node
        int count = 0;
        if (flag_left == true) count++;
        if (flag_right == true) count++;
        if (flag_center == true) count++;
        if (count >= 2) {
            this->result = root;
        }
        return count > 0? true: false;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        result = NULL;
        lca_dfs(root, p, q);
        return result;
    }
};


// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/
// Approach 2: Iterative using parent pointers
// Runtime: 32 ms, faster than 17.43% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage: 17.2 MB, less than 12.18% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *result;
        unordered_map<TreeNode *, TreeNode *> umap;
        queue<TreeNode *> que;
        que.push(root);
        int size;
        bool flag_p = false;
        bool flag_q = false;
        while (que.empty() == false) {
            size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front(); que.pop();
                if (node->left != NULL) {
                    umap[node->left] = node;
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    umap[node->right] = node;
                    que.push(node->right);
                }
                if (node == p) flag_p = true;
                if (node == q) flag_q = true;
                if (flag_p == true && flag_q == true) {
                    break;
                }
            }
        }

        // find all parents of p
        unordered_set<TreeNode *> usp;
        while (p != NULL) {
            usp.insert(p);
            p = umap[p];

        }

        // check if parents of q in parents of p
        while (usp.count(q) == 0) {
            q = umap[q];
        }

        result = q;

        return result;
    }
};