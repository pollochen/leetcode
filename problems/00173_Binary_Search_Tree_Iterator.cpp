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
// brute force (inorder traverse to vector)
// Runtime: 41 ms, faster than 45.27% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 24.3 MB, less than 22.15% of C++ online submissions for Binary Search Tree Iterator.
class BSTIterator {
private:
    vector<int> m_x;
    int         m_idx;
    void inorder(TreeNode *root, vector<int> &x)
    {
        if (root == NULL) return;
        inorder(root->left, x);
        x.push_back(root->val);
        inorder(root->right, x);
    }
public:

    BSTIterator(TreeNode* root) {
        inorder(root, m_x);
        m_idx = 0;
    }

    int next() {
        if (m_idx < m_x.size()) {
            return m_x[m_idx++];
        } else {
            return 0;
        }
    }

    bool hasNext() {
        if (m_idx < m_x.size()) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */