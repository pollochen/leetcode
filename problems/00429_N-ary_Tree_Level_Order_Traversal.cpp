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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        
        queue<Node *> q;
        q.push(root);
        while (q.empty() == false) {
            vector<int> out;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                // publish value in queue
                Node *n = q.front(); q.pop();
                out.push_back(n->val);

                // push all child nodes into queue
                for (int j = 0; j < n->children.size(); j++) {
                    q.push(n->children[j]);
                }
            }
            result.push_back(out);
        }
        return result;
    }
};