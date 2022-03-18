// https://leetcode.com/problems/shuffle-an-array/solution/
class Solution {
private:
    vector<int> nums_org;
    vector<int> nums_shuffle;
public:
    Solution(vector<int>& nums) {
        unsigned seed;
        seed = (unsigned)time(NULL);
        srand(seed);
        nums_org = nums;
    }

    vector<int> reset() {
        return nums_org;
    }

    vector<int> shuffle() {
        nums_shuffle = nums_org;
        int size = nums_org.size();
        for (int i = 0; i < size; i++) {
            int len = size - i;
            int pos = (rand() % len) + i;
            // swap nums[i] with nums[pos+i]
            int tmp = nums_shuffle[pos];
            nums_shuffle[pos] = nums_shuffle[i];
            nums_shuffle[i] = tmp;
        }
        return nums_shuffle;
    }
};
