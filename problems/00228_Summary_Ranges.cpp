	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		if (nums.size() == 0) return result;
		if (nums.size() == 1) {
			result.push_back(to_string(nums[0]));
			return result;
		}

		int size = nums.size();
		int prev = nums[0];
		int start = nums[0];
		for (int i = 1; i < size; i++) {
			int x = nums[i];
			if (x != prev + 1) {
				if (start != prev) {
					result.push_back(to_string(start) + "->" + to_string(prev));
				} else {
					result.push_back(to_string(start));
				}
				start = x;
				if (i == size - 1) {
					// last one
					result.push_back(to_string(x));
				}
			} else {
				if (i == size - 1) {
					// last one
					if (start != x) {
						result.push_back(to_string(start) + "->" + to_string(x));
					} else {
						result.push_back(to_string(start));
					}
				}
			}
			prev = x;
		}

		return result;
	}