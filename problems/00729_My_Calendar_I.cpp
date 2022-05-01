// Runtime: 200 ms, faster than 30.34% of C++ online submissions for My Calendar I.
// Memory Usage: 37.5 MB, less than 93.47% of C++ online submissions for My Calendar I.
class MyCalendar {
    vector<pair<int,int>> m_data;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        pair<int, int> *p;
        for (int i = 0; i < m_data.size(); i++) {
            p = &m_data[i];
            int s1 = p->first;
            int e1 = p->second;
            //if (start >= e1 || end <= s1) {
            if (start < e1 && end > s1) {
                return false;
            }
        }
        m_data.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */