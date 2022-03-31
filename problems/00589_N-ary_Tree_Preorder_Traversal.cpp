/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// interation
// Runtime: 20 ms, faster than 92.98 % of C++ online submissions for N - ary Tree Preorder Traversal.
// Memory Usage : 11.2 MB, less than 77.51 % of C++ online submissions for N - ary Tree Preorder Traversal.
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        stack<Node *> stk; // use stack, not queue
        
        if (root == NULL) return result;

        // push root
        stk.push(root);
        while (stk.empty() == false) {
            Node *node = stk.top();
            stk.pop();
            result.push_back(node->val);
            // pre-order traverse with stack, first in last out
            for (int i = node->children.size() - 1; i >= 0; i--) {
                stk.push(node->children[i]);
            }
        }
        return result;
    }
};

// recursive
// Runtime: 29 ms, faster than 58.94 % of C++ online submissions for N - ary Tree Preorder Traversal.
// Memory Usage : 11.2 MB, less than 77.51 % of C++ online submissions for N - ary Tree Preorder Traversal.
class Solution {
public:
    void preoder_dfs(Node* root, vector<int>& result)
    {
        if (root == NULL) return;
        // publish current value
        result.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            preoder_dfs(root->children[i], result);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> result;
        preoder_dfs(root, result);
        return result;
    }
};