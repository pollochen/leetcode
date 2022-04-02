// Runtime: 264 ms, faster than 24.44% of C++ online submissions for Range Sum Query - Immutable.
// Memory Usage: 17.1 MB, less than 34.36% of C++ online submissions for Range Sum Query - Immutable.
class NumArray {
private:
    vector<int> m_nums;
public:
    NumArray(vector<int>& nums) {
        m_nums = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        if ((left >= 0) && right < m_nums.size()) {
            for (int i = left; i <= right; i++){
                sum += m_nums[i];
            }            
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */