// https://www.cnblogs.com/grandyang/p/4276225.html
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int result = 0;
        while (uset.empty() == false) {
            int count = 1;
            int num = *uset.begin();
            int next = num+1;
            // clear current count
            while (uset.count(num) != 0) uset.erase(num);

            // search left number
            while (uset.count(next) != 0) {
                while (uset.count(next) != 0) uset.erase(next);
                count++;
                next++;
            }

            // search right number
            next = num - 1;
            while (uset.count(next) != 0) {
                while (uset.count(next) != 0) uset.erase(next);
                count++;
                next--;
            }

            result = max(result, count);
        }
        return result;
    }
};