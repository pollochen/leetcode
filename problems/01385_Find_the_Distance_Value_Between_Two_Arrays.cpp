// sort and compare
// Runtime: 52 ms, faster than 10.56% of C++ online submissions for Find the Distance Value Between Two Arrays.
// Memory Usage: 13 MB, less than 73.62% of C++ online submissions for Find the Distance Value Between Two Arrays.
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int result = 0;
        sort(arr2.begin(), arr2.end());
        for (int i = 0; i < arr1.size(); i++) {
            bool flag = true;
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) result++;
        }
        return result;
    }
};

// sort and binary search
// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/discuss/1980520/(Binary-Search)
// Runtime: 7 ms, faster than 96.28% of C++ online submissions for Find the Distance Value Between Two Arrays.
// Memory Usage: 13.1 MB, less than 30.22% of C++ online submissions for Find the Distance Value Between Two Arrays.
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int result = 0;
        int count = 0;
        sort(arr2.begin(), arr2.end());
        for (int i = 0; i < arr1.size(); i++) {
            int l = 0;
            int r = arr2.size() - 1;
            int upper = arr1[i] + d;
            int lower = arr1[i] - d;
            while (l <= r) { // !
                int mid = (l + r) / 2;
                if (arr2[mid] <= upper && arr2[mid] >= lower) {
                    // in [lower, upper] interval
                    count++;
                    break;
                } else if (arr2[mid] > upper) { // check [l, mid-1]
                    r = mid - 1;
                } else {
                    l = mid + 1; // check [mid+1, right]
                }
            }
        }
        return arr1.size() - count;
    }
};