// https://www.cnblogs.com/grandyang/p/5454125.html
// Runtime: 47 ms, faster than 5.42 % of C++ online submissions for Top K Frequent Elements.
// Memory Usage : 13.7 MB, less than 71.77 % of C++ online submissions for Top K Frequent Elements.
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> um;
		// build the frequency of each number
		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}
		// build a priority queue<freq, number>, maximum frequency first
		// in map, first = number, second = freq
		priority_queue<pair<int, int>> pq;
		for (auto it : um) {
			pq.push({ it.second, it.first });
		}
		// output first k elements in priority queue
		vector<int> result;
		for (int i = 0; i < k; i++) {
			result.push_back(pq.top().second);
			pq.pop();
		}
		return result;
	}
};

void test_347_Top_K_Frequent_Elements(void)
{
	Solution s;
	print_vector_int(s.topKFrequent(vector<int>{1, 1, 1, 2, 2, 3}, 2));
	print_vector_int(s.topKFrequent(vector<int>{1}, 1));
}