// LinkedList version
// Runtime: 6 ms, faster than 12.83% of C++ online submissions for Implement Queue using Stacks.
// Memory Usage: 7 MB, less than 88.60% of C++ online submissions for Implement Queue using Stacks.
class MyQueue {
public:
    ListNode* m_head;
    ListNode* m_tail;
    int       count;
    MyQueue(): m_head(NULL) , m_tail(NULL), count(0) {
    }

    void push(int x) {
        ListNode* node = new ListNode(x);
        if (m_head == NULL) {
            m_head = node;
            m_tail = node;
        } else {
            m_tail->next = node;
            m_tail = node;
        }
        count++;
    }

    int pop() {
        int x = 0;
        if (count > 0) {
            ListNode *node = m_head;
            x = m_head->val;
            m_head = m_head->next;
            delete node;
            count--;
        }
        return x;
    }

    int peek() {
        int x = 0;
        if (count > 0) {
            x = m_head->val;
        }
        return x;
    }

    bool empty() {
        if (count == 0) return true;
        else return false;
    }
};

// stack version
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
// Memory Usage: 6.9 MB, less than 88.60% of C++ online submissions for Implement Queue using Stacks.
class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    MyQueue() {
    }

    void push(int x) {
        // pop and push stk1 into stk2
        while (stk1.empty() == false) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        // push x into stk1 (last in last out)
        stk1.push(x);

        // pop and push stk2 into stk1
        while (stk2.empty() == false) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }

    int pop() {
        int x = stk1.top();
        stk1.pop();
        return x;
    }

    int peek() {
        int x = stk1.top();
        return x;
    }

    bool empty() {
        return stk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */