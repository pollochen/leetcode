// priority queue with smallest on top
// keep k elements in the queue, top is the result
// Runtime: 45 ms, faster than 53.48% of C++ online submissions for Kth Largest Element in a Stream.
// Memory Usage: 19.9 MB, less than 63.09% of C++ online submissions for Kth Largest Element in a Stream.
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int m_k;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (pq.size() > k) {
            pq.pop();
        }
        m_k = k;
    }

    int add(int val) {
        pq.push(val);
        while (pq.size() > m_k) {
            pq.pop();
        }
        if (pq.size() == m_k) {
            return pq.top();
        } else {
            return 0;
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */