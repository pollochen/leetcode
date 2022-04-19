// brute force
// Runtime: 3 ms, faster than 43.09% of C++ online submissions for Combination Sum III.
// Memory Usage: 6.7 MB, less than 28.93% of C++ online submissions for Combination Sum III.
class Solution {
public:
    void x(int k, int n, int start, vector<int> &out, vector<bool> visited, vector<vector<int>> &result)
    {
        if ((n == 0) && (k == 0)) {
            result.push_back(out);
            return;
        }
        
        if ((n == 0) || (k == 0)) {
            return;
        }
        
        for (int i = start; i <= 9; i++) {
            if (visited[i] == false) {
                visited[i] = true;
                out.push_back(i);
                x(k-1, n - i, i+1, out, visited, result);
                visited[i] = false;
                out.pop_back();
            }
        }   
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> out;
        vector<bool> visited(10, false);
        vector<vector<int>> result;
        x(k, n, 1, out, visited, result);
        return result;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum III.
// Memory Usage: 6.7 MB, less than 37.55% of C++ online submissions for Combination Sum III.
class Solution {
public:
    void x(int k, int n, int start, vector<int> &out, vector<bool> visited, vector<vector<int>> &result)
    {
        if ((n == 0) && (k == 0)) {
            result.push_back(out);
            return;
        }
        
        if ((n == 0) || (k == 0) || (start > 9)) { // add condition check
            return;
        }
        
        for (int i = start; i <= 9; i++) {
            if ((n - i) < 0) break; // add condition check
            if (visited[i] == false) {
                visited[i] = true;
                out.push_back(i);
                x(k-1, n - i, i+1, out, visited, result);
                visited[i] = false;
                out.pop_back();
            }
        }   
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> out;
        vector<bool> visited(10, false);
        vector<vector<int>> result;
        x(k, n, 1, out, visited, result);
        return result;  
    }
};