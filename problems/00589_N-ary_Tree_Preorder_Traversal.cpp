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

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        stack<Node *> stk;
        
        if (root == NULL) return result;

        // push root
        stk.push(root);
        while (stk.empty() == false) {
            Node *node = stk.top();
            stk.pop();
            result.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; i--) {
                stk.push(node->children[i]);
            }
        }
        return result;
    }
};