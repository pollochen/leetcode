// 1 stack version
// push previous min value into stack 
// Runtime: 29 ms, faster than 58.77% of C++ online submissions for Min Stack.
// Memory Usage: 16.4 MB, less than 68.29% of C++ online submissions for Min Stack.
class MinStack {
public:
    stack<int> m_stk;
    int        m_min;
    MinStack() {
        //m_stk.clear();
        m_min = INT_MAX;
    }
    
    void push(int val) {
        if (val <= m_min) {
            // push previous min value, even for same min value
            m_stk.push(m_min);
            m_min = val;
        }
        m_stk.push(val);
    }
    
    void pop() {
        if (m_stk.empty() == false) {
            int x = m_stk.top();
            m_stk.pop();
            if (x == m_min) {
                // poping min value, next top would have next min value
                m_min = m_stk.top();
                m_stk.pop();
            }             
        }
    }
    
    int top() {
        return m_stk.top();  
    }
    
    int getMin() {
        return m_min;
    }
};

// 2 stack version
// Runtime: 27 ms, faster than 65.53% of C++ online submissions for Min Stack.
// Memory Usage: 16.4 MB, less than 68.29% of C++ online submissions for Min Stack.
class MinStack {
public:
    stack<int> m_stk;
    stack<int> m_stk_min;
    int        m_min;
    MinStack() {
        //m_stk.clear();
        m_min = INT_MAX;
    }
    
    void push(int val) {
        if (val <= m_min) {
            // push previous min value, even for same min value
            m_stk_min.push(m_min);
            m_min = val;
        }
        m_stk.push(val);
    }
    
    void pop() {
        if (m_stk.empty() == false) {
            int x = m_stk.top();
            m_stk.pop();
            if (x == m_min) {
                // poping min value
                m_min = m_stk_min.top();
                m_stk_min.pop();
            }             
        }
    }
    
    int top() {
        return m_stk.top();  
    }
    
    int getMin() {
        return m_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */