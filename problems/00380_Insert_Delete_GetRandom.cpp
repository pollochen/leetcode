// https://www.cnblogs.com/grandyang/p/5740864.html
class RandomizedSet {
public:
	unordered_map<int, int> um; // val -> position in data array
	vector<int> data;
	RandomizedSet() {
		srand((unsigned)time(NULL));
	}

	bool insert(int val) {
		if (um.count(val) == 0) {
			// inset it to data
			data.push_back(val);
			// save the position of val in data array
			um[val] = data.size() - 1;
			return true;
		} else {
			return false;
		}
	}

	bool remove(int val) {
		if (um.count(val) == 0) {
			return false;
		}
		int pos = um[val];
		// remove val from data
		// 1. swap it with last element of data array
		int x = data[data.size() - 1];
		data[pos] = data[data.size() - 1];
		// 2. remove last element of data array
		data.pop_back();
		// 3. update position of swapped last element
		um[x] = pos;

		// erase val from the map
		um.erase(val);

		return true;
	}

	int getRandom() {
		int pos = rand() % data.size();
		return data[pos];
	}
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 
 void test_00380_Insert_Delete_GetRandom(void)
{

	RandomizedSet rs;
	printf("%d, ", rs.insert(1));
	printf("%d, ", rs.remove(2));
	printf("%d, ", rs.insert(2));
	printf("%d, ", rs.getRandom());
	printf("%d, ", rs.remove(1));
	printf("%d, ", rs.insert(2));
	printf("%d, ", rs.getRandom());
	printf("\n");

	RandomizedSet rs2;
	printf("%d, ", rs2.insert(0));
	printf("%d, ", rs2.insert(1));
	printf("%d, ", rs2.remove(0));
	printf("%d, ", rs2.insert(2));
	printf("%d, ", rs2.remove(1));
	printf("%d, ", rs2.getRandom());
	printf("\n");

}