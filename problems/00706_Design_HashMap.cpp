// brute force
// Runtime: 145 ms, faster than 79.37% of C++ online submissions for Design HashMap.
// Memory Usage: 190.6 MB, less than 40.96% of C++ online submissions for Design HashMap.
class MyHashMap {
private:
    int *m_value;    
public:
    MyHashMap() {
        m_value = new int[1000001];
        memset(m_value, -1, sizeof(int) * 1000001);
    }
    
    void put(int key, int value) {
        m_value[key] = value;
    }
    
    int get(int key) {
        return m_value[key];
    }
    
    void remove(int key) {
        m_value[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */