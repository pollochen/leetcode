// slow version: 18.02%
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		for (int i = 0; i < nums1.size(); i++) {
			int x = nums1[i];
			bool flag_found = false;
			bool flag_pushed = false;
			for (int j = 0; j < nums2.size(); j++) {
				if ((flag_found == true) && (nums2[j] > x)) {
					result.push_back(nums2[j]);
					flag_pushed = true;
					break;
				}
				if (nums2[j] == x) {
					flag_found = true;
				}
			}
			if (flag_pushed == false) result.push_back(-1);
		}
		return result;
	}
};

// faster version: 31.04%
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_map<int, int> umap;
		stack<int> stk;
		for (int i = nums2.size() - 1; i >= 0; i--) {
			while ((stk.empty() == false) && (stk.top() < nums2[i])) {
				stk.pop();
			}
			if (stk.empty() == true) umap[nums2[i]] = -1;
			else umap[nums2[i]] = stk.top();
            stk.push(nums2[i]);
		}
		for (int i = 0; i < nums1.size(); i++) {
			result.push_back(umap[nums1[i]]);
		}
		return result;
	}
};