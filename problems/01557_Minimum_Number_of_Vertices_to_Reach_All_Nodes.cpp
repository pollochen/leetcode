// Runtime: 481 ms, faster than 28.70% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
// Memory Usage: 108.1 MB, less than 19.87% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> linked(n);
        vector<int> result;
		// create a reverse link from [from -> to] to [to <- from 1, from 2]
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to   = edges[i][1];
            linked[to].push_back(from);
        }
        
		// if a node is not lined, then we must start from it
        for (int i = 0; i < n; i++) {
            if (linked[i].size() == 0) result.push_back(i);
        }
        return result;
    }
};

// Runtime: 378 ms, faster than 58.97% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
// Memory Usage: 94.3 MB, less than 83.83% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> linked(n, false);
        vector<int> result;
		// create a reverse link from [from -> to] to [to <- from 1, from 2]
		// just mark it as linked		
        for (int i = 0; i < edges.size(); i++) {
            int to   = edges[i][1];
            linked[to] = true;
        }
        
		// if a node is not lined, then we must start from it
        for (int i = 0; i < n; i++) {
            if (linked[i] == false) result.push_back(i);
        }
        return result;
    }
};