// https://leetcode.com/problems/smallest-string-with-swaps/solution/
// TLE version (union set quick find)
class UnionFind {
    vector<int> root;
public:
    UnionFind(int size) : root(size) {
        // set root of i as i
        for (int i = 0; i < size; i++) {
            root[i] = i;
        }
    }
    int find(int x) {
        return root[x];
    }
    void union_set(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            // hook root of node i = root_y to root_x
            for (int i = 0; i < root.size(); i++) {
                if (root[i] == root_y) {
                    root[i] = root_x;
                }
            }
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.length());

        // build union set from pairs
        for (int i = 0; i < pairs.size(); i++) {
            int src = pairs[i][0];
            int dst = pairs[i][1];
            uf.union_set(src, dst);
        }

        // build [index chars] groups from union set (since they have same root index)
        unordered_map<int, vector<int>> umap; // root index -> nodes have same root index
        for (int i = 0; i < s.length(); i++) {
            int root = uf.find(i);
            umap[root].push_back(i);
        }

        string result = s;
        // traverse each group
        for (auto x : umap) {
            vector<char> chars;
            vector<int>  indices = x.second;
            // collect all characters in the this group
            for (int idx : indices) {
                chars.push_back(s[idx]);
            }
            // sort characters (lexicographically smallest string )
            sort(chars.begin(), chars.end());
            // sort indices (smallest index first)
            sort(indices.begin(), indices.end());
            for (int i = 0; i < indices.size(); i++) {
                result[indices[i]] = chars[i];
            }
        }

        return result;
    }
};

// https://en.wikipedia.org/wiki/Disjoint-set_data_structure#Merging_two_sets
// better union_set (union by size)
// Runtime: 185 ms, faster than 80.91% of C++ online submissions for Smallest String With Swaps.
// Memory Usage: 52.1 MB, less than 62.15% of C++ online submissions for Smallest String With Swaps.

class UnionFind {
    vector<int> root;
    vector<int> rank;
public:
    UnionFind(int size) : root(size), rank(size) {
        // set root of i as i
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        while (x != root[x]) {
            x = root[x];
        }
        return x;
    }
    void union_set(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            if (rank[root_x] >= rank[root_y]) { // size of x is bigger than y
                root[root_y] = root_x;        // hook y to x
                rank[root_x] += rank[root_y]; // add union size of x with y
            } else {                          // size of y is bigger than x
                root[root_x] = root_y;        // hook x to y
                rank[root_y] += rank[root_x]; // add union size of y with x
            }
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.length());

        // build union set from pairs
        for (int i = 0; i < pairs.size(); i++) {
            int src = pairs[i][0];
            int dst = pairs[i][1];
            uf.union_set(src, dst);
        }

        // build [index chars] groups from union set (since they have same root index)
        unordered_map<int, vector<int>> umap; // root index -> nodes have same root index
        for (int i = 0; i < s.length(); i++) {
            int root = uf.find(i);
            umap[root].push_back(i);
        }

        string result = s;
        // traverse each group
        for (auto x : umap) {
            vector<char> chars;
            vector<int>  indices = x.second;
            // collect all characters in the this group
            for (int idx : indices) {
                chars.push_back(s[idx]);
            }
            // sort characters (lexicographically smallest string )
            sort(chars.begin(), chars.end());
            // no need to sort indices because the index was added in ascending order
            // sort indices (smallest index first)
            //sort(indices.begin(), indices.end());
            for (int i = 0; i < indices.size(); i++) {
                result[indices[i]] = chars[i];
            }
        }

        return result;
    }
};