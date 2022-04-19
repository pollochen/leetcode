// brute force 
// search manager and BFS
// TLE
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<int> que; // index base
        vector<int> time(n, 0);
        que.push(headID);
        int result = 0;
        int size;
        time[headID] = informTime[headID];
        while (que.empty() == false) {
            size = que.size();
            for (int i = 0; i < size; i++) {
                int x = que.front(); que.pop();
                
                for (int j = 0; j < n; j++) {
                    if (manager[j] == x) {
                        time[j] = time[x] + informTime[j];
                        que.push(j);
                        manager[j] = -1;
                        result = max(result, time[j]);
                    }
                }
            }
        }
        return result;
    }
};

// make tree and DFS for max path length
// Runtime: 423 ms, faster than 51.17% of C++ online submissions for Time Needed to Inform All Employees.
// Memory Usage: 134.8 MB, less than 28.61% of C++ online submissions for Time Needed to Inform All
class Solution {
public:
    int get_len(int idx, vector<vector<int>> &tree, vector<int>& informTime) {
        vector<int> subs = tree[idx];
        if (subs.size() == 0) {
            // last one
            return 0;
        }
        
        int result = 0;
        int len;
        for (int i = 0; i < subs.size(); i++) {
            len = get_len(subs[i], tree, informTime) + informTime[idx];
            result = max(result, len);
        }
        return result;        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> tree(n); // index base 
        // manager 0: subordination1 -> subordination2 -> ...
		// manager 1: subordination1 -> subordination2 -> ...
		// manager k: empty
		// manager n-1: subordination1 -> subordination2 -> ...
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                tree[manager[i]].push_back(i);
            }
        }
        return get_len(headID, tree, informTime);
    }
};
// make tree and DFS for max path length (code optimization)
// Runtime: 309 ms, faster than 77.09% of C++ online submissions for Time Needed to Inform All Employees.
// Memory Usage: 122.1 MB, less than 57.26% of C++ online submissions for Time Needed to Inform All
class Solution {
public:
    int get_len(int idx, vector<vector<int>> &tree, vector<int>& informTime) {
        vector<int> &subs = tree[idx];
        if (subs.size() == 0) {
            // last one
            return 0;
        }
        
        int result = 0;
        int len;
        for (int i = 0; i < subs.size(); i++) {
            len = get_len(subs[i], tree, informTime) + informTime[idx];
            result = max(result, len);
        }
        return result;        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> tree(n); // index base 
        // manager 0: subordination1 -> subordination2 -> ...
		// manager 1: subordination1 -> subordination2 -> ...
		// manager k: empty
		// manager n-1: subordination1 -> subordination2 -> ...
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                tree[manager[i]].push_back(i);
            }
        }
        return get_len(headID, tree, informTime);
    }
};