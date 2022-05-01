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

// use stack
// Runtime: 27 ms, faster than 88.85% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 24.1 MB, less than 87.61% of C++ online submissions for Binary Search Tree Iterator.
class BSTIterator {
private:
    stack<TreeNode *> m_stk;
    TreeNode *m_cur;
public:

    BSTIterator(TreeNode* root) {
        // traverse left until NULL and push eahc node into stack
        m_cur = root;
        while (m_cur != NULL) {
            m_stk.push(m_cur);
            m_cur = m_cur->left;
        }
    }

    int next() {
        if (m_stk.empty() == false) {
            TreeNode *node = m_stk.top();
            m_stk.pop();
            int val = node->val;
            // traverse left of it's right node until NULL and push eahc node into stack
            m_cur = node->right;
            while (m_cur != NULL) {
                m_stk.push(m_cur);
                m_cur = m_cur->left;
            }
            return val;
        }
        return 0;
    }

    bool hasNext() {
        if (m_stk.empty() == true) {
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */