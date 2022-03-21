// use map
// Runtime: 8 ms, faster than 56.41 % of C++ online submissions for Intersection of Two Arrays II.
// Memory Usage : 10.7 MB, less than 21.00 % of C++ online submissions for Intersection of Two Arrays II.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (mp[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return result;
    }
};

// use unordered map
// Runtime: 4 ms, faster than 87.22 % of C++ online submissions for Intersection of Two Arrays II.
// Memory Usage : 10.8 MB, less than 21.00 % of C++ online submissions for Intersection of Two Arrays II.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (mp[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return result;
    }
};

// use array as map
// Runtime: 9 ms, faster than 42.61 % of C++ online submissions for Intersection of Two Arrays II.
// Memory Usage : 10 MB, less than 94.11 % of C++ online submissions for Intersection of Two Arrays II.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int freqs[1001];
        memset(freqs, 0, sizeof(freqs));
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            freqs[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (freqs[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                freqs[nums2[i]]--;
            }
        }
        return result;
    }
};