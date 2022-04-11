// https://leetcode.com/problems/last-stone-weight/discuss/1921100/Simple-easy-c%2B%2B-solution
// Runtime: 4 ms, faster than 37.54% of C++ online submissions for Last Stone Weight.
// Memory Usage: 7.6 MB, less than 78.96% of C++ online submissions for Last Stone Weight.
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int x, y;
        while (pq.size() > 1) {
            x = pq.top(); pq.pop();
            y = pq.top(); pq.pop();
            if (x != y) pq.push(abs(x-y));
        }
        if (pq.size() == 1) return pq.top();
        else return 0;
    }
};