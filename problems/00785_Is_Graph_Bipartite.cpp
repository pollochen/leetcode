// BFS coloring node and check
// Runtime: 29 ms, faster than 65.13% of C++ online submissions for Is Graph Bipartite?.
// Memory Usage: 13.7 MB, less than 41.19% of C++ online submissions for Is Graph Bipartite?.

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color;
        int visit_count = 0;
        vector<int> colors(n, -1);
        vector<bool> visited(n, false);
        queue<int> que;
        while (que.empty() == false || visit_count < n) {

            if (que.empty() == true) {
                // find an un-visited node and push it to queue for orphan nodes
                // node[0] might be orphan node
                for (int i = 0; i < n; i++) {
                    if (visited[i] == false) {
                        colors[i] = 0;
                        visited[i] = true;
                        visit_count++;
                        que.push(i);
                        break;
                    }
                }
                continue;
            }

            int root = que.front();
            que.pop();

            vector<int> children = graph[root];
            int color = colors[root];
            int next_color = (color + 1) % 2;
            for (int child : children) {
                int color_child = colors[child];
                if (color_child != -1) {
                    // the child has colored, check color
                    // the color of child should be different with root's.
                    if (color_child != next_color) {
                        return false;
                    }
                } else {
                    // the child is not colored, color it
                    colors[child] = next_color;
                }
                if (visited[child] == false) {
                    visited[child] = true;
                    visit_count++;
                    que.push(child);
                }
            }
        }
        return true;
    }
};