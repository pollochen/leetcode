// dfs with visited memorization
// Runtime: 31 ms, faster than 37.00% of C++ online submissions for All Paths From Source to Target.
// Memory Usage: 11.5 MB, less than 66.43% of C++ online submissions for All Paths From Source to Target.
class Solution {
public:
    void x(vector<vector<int>>& graph, int idx_cur, vector<bool> &visited, vector<int> &out, vector<vector<int>> &result)
    {
        if (idx_cur == graph.size() - 1) {
            result.push_back(out);
            return;
        }

        vector<int> nexts = graph[idx_cur];
        int next;
        for (int i = 0; i < nexts.size(); i++) {
            next = nexts[i];
            if (visited[next] == false) {
                visited[next] = true;
                out.push_back(next);
                x(graph, next, visited, out, result);
                visited[next] = false;
                out.pop_back();
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         vector<bool> visited(graph.size(), false);
         vector<int> out;
         vector<vector<int>> result;
         visited[0] = true;
         out.push_back(0);
         x(graph, 0, visited, out, result);
         return result;
    }
};