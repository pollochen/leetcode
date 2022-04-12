// brute force
// Runtime: 55 ms, faster than 47.36% of C++ online submissions for Design Linked List.
// Memory Usage: 19.7 MB, less than 29.12% of C++ online submissions for Design Linked List.
struct LL {
    struct LL *next;
    int        val;
};

class MyLinkedList {
    struct LL *m_Head;
    int        m_Count;
public:
    MyLinkedList() {
        m_Head = NULL;
        m_Count = 0;
    }
    
    int get(int index) {
        if (index < m_Count) {
            struct LL *ll = m_Head;
            while (index != 0) {
                ll = ll->next;
                index--;
            }
            return ll->val;
        } else {
            return -1;
        }
    }
    
    void addAtHead(int val) {
        struct LL *node = (struct LL *)malloc(sizeof(struct LL));
        
        node->val = val;
        node->next = NULL;

        if (m_Count == 0) {
            m_Head = node;
        } else {
            node->next = m_Head;
            m_Head = node;
        }
        m_Count++;
    }
    
    void addAtTail(int val) {
        struct LL *ll = m_Head;

        struct LL *node = (struct LL *)malloc(sizeof(struct LL));
        node->val = val;
        node->next = NULL;
        
        if (m_Count == 0) {
            m_Head = node;
        } else {
            struct LL *prev = NULL;
            while (ll != NULL) {
                prev = ll;
                ll = ll->next;
            }
            prev->next = node;
        }
        m_Count++;
    }
    
    void addAtIndex(int index, int val) {
        if (index == m_Count) {
            addAtTail(val);
        } else if (index == 0) {
            addAtHead(val);
        } else if (index < m_Count) {
            struct LL *ll = m_Head;
            struct LL *prev = NULL;
            while (index != 0) {
                prev = ll;
                ll = ll->next;
                index--;
            }
            
            struct LL *node = (struct LL *)malloc(sizeof(struct LL));
            node->val = val;
            node->next = prev->next;            
            prev->next = node;                

            m_Count++;
        } else {
            return;
        }
    }
    
    void deleteAtIndex(int index) {
        if (m_Count == 0) return;

        if (index < m_Count) {
            if (index == 0) {
                struct LL *tmp = m_Head->next;
                free(m_Head);
                m_Head = tmp;
                m_Count--;
            } else {
                struct LL *ll = m_Head;
                struct LL *prev;
                while (index != 0) {
                    prev = ll;
                    ll = ll->next;
                    index--;
                }
                prev->next = ll->next;
                free(ll);
                m_Count--;
            }            
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */