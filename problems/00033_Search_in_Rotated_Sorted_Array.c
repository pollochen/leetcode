// https://www.cnblogs.com/grandyang/p/4325648.html
int bs(int* nums, int numsSize, int l, int r, int target)
{
	if (l > r) return -1;
	if (l == r) {
		if (nums[l] == target) return l;
		else return -1;
	}
	int mid = (l + r) / 2;
	if (nums[mid] == target) return mid;
	if (nums[mid] < nums[r]) {
		// ascending order in [mid+1, r]
		if ((nums[mid] < target) && (target <= nums[r])) {
			// target is in [mid+1, r]
			return bs(nums, numsSize, mid + 1, r, target);
		} else {
			// maybe target is in [l, mid-1]
			return bs(nums, numsSize, l, mid-1, target);
		} 
	} else {
		// ascending order in [l, mid-1]
		if ((nums[l] <= target) && (target < nums[mid])) {
			// target is in [l, mid-1]
			return bs(nums, numsSize, l, mid-1, target);
		} else {
			// maybe target is in [mid+1, r]
			return bs(nums, numsSize, mid + 1, r, target);
		}
	}
}

int search(int* nums, int numsSize, int target) {
	return bs(nums, numsSize, 0, numsSize - 1, target);
}