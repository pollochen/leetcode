class DoubleLinkedList {
public:
	DoubleLinkedList* next;
	DoubleLinkedList* prev;
	int val;
	int key;
	DoubleLinkedList(): val(-1), next(NULL), prev(NULL), key(0) {

	}
} ;

class LRUCache {
private:
	DoubleLinkedList* m_head;
	DoubleLinkedList* m_end;
	int m_capacity;
	int m_count;
	unordered_map<int, DoubleLinkedList *> map;
	void UpdateCache(DoubleLinkedList *Node)
	{
		// put this node to first position of list
		Node->prev = m_head;
		Node->next = m_head->next;
		m_head->next->prev = Node;
		m_head->next = Node;
	}
	void RemoveLeastUsed(void)
	{
		if (m_count > m_capacity) {
			// remove least used node from list
			DoubleLinkedList* node = m_end->prev;
			node->prev->next = m_end;
			m_end->prev = node->prev;
			// remove least used node from map
			map.erase(node->key);
			delete node;
		}
	}
public:
	LRUCache(int capacity) {
		m_head = new DoubleLinkedList();
		m_end  = new DoubleLinkedList();
		m_head->next = m_end;
		m_end->prev  = m_head;
		m_capacity = capacity;
		m_count = 0;
	}

	int get(int key) {
		if (map.count(key) > 0) {
			DoubleLinkedList* node = map[key];
			// 1. detach this node
			node->prev->next = node->next;
			node->next->prev = node->prev;
			// put this node to first position of list
			UpdateCache(node);
			return node->val;
		}
		return -1;
	}

	void put(int key, int value) {
		if (map.count(key) > 0) {
			// already in the map
			// update cache

			DoubleLinkedList* node = map[key];
			// 1. detach this node
			node->prev->next = node->next;
			node->next->prev = node->prev;
            node->val = value; // update value

			// 2. put this node to first position of list
			UpdateCache(node);
		} else {
			// not in the map
			DoubleLinkedList* node = new DoubleLinkedList();
			node->val = value;
			node->key = key;
			map[key] = node;
			// update cache
			// put this node to first position of list
			UpdateCache(node);
			m_count++;
			RemoveLeastUsed();
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 void test_00146_LRU_Cache(void)
{
	LRUCache lRUCache(2);
	lRUCache.put(1, 1); // cache is {1=1}
	lRUCache.put(2, 2); // cache is {1=1, 2=2}
	printf("%d\n", lRUCache.get(1));    // return 1
	lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
	printf("%d\n", lRUCache.get(2));    // returns -1 (not found)
	lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
	printf("%d\n", lRUCache.get(1));    // return -1 (not found)
	printf("%d\n", lRUCache.get(3));    // return 3
	printf("%d\n", lRUCache.get(4));    // return 4
}