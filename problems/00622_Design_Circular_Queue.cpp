// Runtime: 20 ms, faster than 95.93% of C++ online submissions for Design Circular Queue.
// Memory Usage: 16.9 MB, less than 54.71% of C++ online submissions for Design Circular Queue.
class MyCircularQueue {
    int *m_data;
    int  m_idx_w;
    int  m_idx_r;
    int  m_size;
public:
    MyCircularQueue(int k) {
        m_data = new int[k+1];
        m_idx_w = 0;
        m_idx_r = 0;
        m_size  = k+1;
    }

    bool enQueue(int value) {
        if (isFull() == false) {
            m_data[m_idx_w] = value;
            m_idx_w = (m_idx_w + 1) % m_size;
            return true;
        } else {
            return false;
        }
    }

    bool deQueue() {
        if (isEmpty() == false) {
            m_idx_r = (m_idx_r + 1) % m_size;
            return true;
        } else {
            return false;
        }
    }

    int Front() {
        if (isEmpty() == false) {
            return m_data[m_idx_r];
        } else {
            return -1;
        }
    }

    int Rear() {
        if (isEmpty() == false) {
            if (m_idx_w == 0) {
                return m_data[m_size - 1];
            } else {
                return m_data[m_idx_w - 1];
            }
        } else {
            return -1;
        }

    }

    bool isEmpty() {
        if (m_idx_w == m_idx_r) return true;
        else return false;
    }

    bool isFull() {
        if (((m_idx_w + 1) % m_size) == m_idx_r) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */