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
    vector<int> postorder(Node* root) {
        vector<int> result;
        stack<Node *> stk;

        if (root == NULL) {
            return result;
        }

        Node* node_cur;
        // push root
        stk.push(root);
        while (stk.empty() == false) {
            // 1. pick one node
            node_cur = stk.top();

            if (node_cur->children.size() == 0) {
                stk.pop();
                // 2. publish the value if no children
                result.push_back(node_cur->val);       
            }
       
            // 3. push all children nodes
            for (int i = node_cur->children.size() - 1; i >= 0; i--) {
                stk.push(node_cur->children[i]);
            }
            // 4. remove all children nodes
            node_cur->children.clear();
        }
        return result;               
    }
};