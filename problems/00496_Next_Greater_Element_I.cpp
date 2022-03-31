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

// monotonic stack with map
// Runtime: 8 ms, faster than 66.76 % of C++ online submissions for Next Greater Element I.
// Memory Usage : 9 MB, less than 15.55 % of C++ online submissions for Next Greater Element I.
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_map<int, int> umap;
		stack<int> stk;
		// we want to keep elements larger than current elements in stack
		// then the top of the stack is the answer if current element
		// we traverse from last element
		for (int i = nums2.size() - 1; i >= 0; i--) {
			// if the values in stack smaller than current, pop them (they are not answer)
			while ((stk.empty() == false) && (stk.top() < nums2[i])) {
				stk.pop();
			}
			// if the stack is empty, means no values larger than current
			// if the stack is not empty, means top values is the answer
			if (stk.empty() == true) umap[nums2[i]] = -1;
			else umap[nums2[i]] = stk.top();
            stk.push(nums2[i]);
		}
		// now we have answer for each element in nums2, easy to get answer for nums1
		for (int i = 0; i < nums1.size(); i++) {
			result.push_back(umap[nums1[i]]);
		}
		return result;
	}
};