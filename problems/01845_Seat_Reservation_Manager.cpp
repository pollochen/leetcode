// priority queue
// Runtime: 408 ms, faster than 85.03% of C++ online submissions for Seat Reservation Manager.
// Memory Usage: 147.7 MB, less than 52.97% of C++ online submissions for Seat Reservation Manager.
class SeatManager {
    priority_queue<int, vector<int>, greater<int>> m_pq;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            m_pq.push(i);
        }
    }

    int reserve() {
        int x = m_pq.top();
        m_pq.pop();
        return x;
    }

    void unreserve(int seatNumber) {
        m_pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */