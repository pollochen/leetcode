// better solution: https://leetcode.com/problems/rotate-array/discuss/1817326/Java-Explained-Time-%3A-O(n)-Space-%3A-O(1)-Runtime%3A-0-ms-100-faster
// faster version (in place)
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		k = k % size;
		if ((k == 0) || (size == 1)) return;

		vector<int> saved(k);
		vector<int> tmp(k);

		int idx_end = ((size / k) - 1) * k;
		for (int i = 0; i <= idx_end; i += k) {
			// save next values
			for (int j = 0; j < k; j++) {
				tmp[j] = nums[(i + k + j) % size];
			}
			// shift values
			if (i == 0) {
				for (int j = 0; j < k; j++) {
					nums[(i + j + k) % size] = nums[i + j];
				}
			} else {
				for (int j = 0; j < k; j++) {
					nums[(i + j + k) % size] = saved[j];
				}
			}
			saved = tmp;
		}
		// copy last
		for (int i = idx_end + k; i < size; i++) {
			nums[(i + k) % size] = saved[i - idx_end - k];
		}
	}
};

// slow version with memcpy
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		k = k % size;
		if ((k == 0) || (size == 1)) return;
		vector<int> result(nums.size());

		for (int i = 0; i < k; i++) {
			int idx = i;
			while (idx < size) {
				result[(idx + k) % size] = nums[idx];
				idx += k;
			}
		}
		nums = result;
    }
};

void print_vector_int(vector<int> &x)
{
	printf("[");
	for (int i = 0; i < x.size(); i++) {
		printf("%d, ", x[i]);
	}
	printf("]\n");
}

void test_189_Rotate_Array(void)
{
	Solution s;
	vector<int> nums_1 = {1, 2, 3, 4, 5, 6, 7};
	vector<int> nums_2 = { -1, -100, 3, 99};
	vector<int> nums_3 = { 1 };
	vector<int> nums_4 = { 1, 2 };
	s.rotate(nums_1, 3);
	print_vector_int(nums_1);
	s.rotate(nums_2, 2);
	print_vector_int(nums_2);
	s.rotate(nums_3, 0);
	print_vector_int(nums_3);
	s.rotate(nums_3, 1);
	print_vector_int(nums_3);
	s.rotate(nums_4, 2);
	print_vector_int(nums_4);

}