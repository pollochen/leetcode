// brute force
// Runtime: 92 ms, faster than 15.90% of C++ online submissions for Find the Winner of the Circular Game.
// Memory Usage: 6 MB, less than 73.65% of C++ online submissions for Find the Winner of the Circular Game.
class Solution {
public:
    int remove(vector<bool> &x, int start, int steps)
    {
        int n = x.size();
		// find next to remove
		// skip k elements
        while (steps != 0) {
            if (x[start % n] == true) {
                steps--;
            }
            start++;
        }

		// find next elelemt to remove
        while (x[start % n] == false) {
            start++;
        }

		// makr it as removed
        x[start % n] = false;
        //printf("R%d ", start % n);
		
		// find next elelemt to start
        while (x[start % n] == false) {
            start++;
        }
        return start % n;
    }

    int findTheWinner(int n, int k) {
        vector<bool> x(n, true);
        int start = 0;
        k = (k-1) % n;
        while (n > 1) {
            start = remove(x, start, k);
            //printf("S%d ", start);
            n--;
        }
        return start + 1;
    }
};
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/discuss/1926155/Simple-queue-in-c%2B%2B
// queue
// Runtime: 92 ms, faster than 15.90% of C++ online submissions for Find the Winner of the Circular Game.
// Memory Usage: 24.5 MB, less than 15.13% of C++ online submissions for Find the Winner of the Circular
class Solution {
public:

    int findTheWinner(int n, int k) {
        queue<int> que;
        for (int i = 0; i < n; i++) {
            que.push(i+1);
        }
            
        int idx = 1;
        while (que.size() != 1) {
            if (idx == k) {
                // remove this element and restart count
                que.pop();
                idx = 1;
            } else {
                // put first element to last of queue
                int x = que.front(); que.pop();
                que.push(x);
                // increase count
                idx++;
            }
        }
        return que.front();
    }
};