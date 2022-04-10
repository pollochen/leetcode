// https://leetcode.com/problems/k-closest-points-to-origin/solution/
// Approach 1: Sort with Custom Comparator
// TLE
bool comp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> x;
        int distance;
        for (int i = 0; i < points.size(); i++) {
            distance = points[i][0] * points[i][0] + points[i][1] * points[i][1]; 
            x.push_back({distance, i});
        }
        sort(x.begin(), x.end(), comp);
        
        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(points[x[i][1]]);
        }
        return result;
    }
};

// Approach 2: Max Heap or Max Priority Queue
// Runtime: 372 ms, faster than 40.77% of C++ online submissions for K Closest Points to Origin.
// Memory Usage: 62.4 MB, less than 73.59% of C++ online submissions for K Closest Points to Origin.
class Solution {
private:
    int get_distance(vector<int> &point)
    {
        return point[0] * point[0] + point[1] * point[1]; 
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq; // max heap
        int distance;
        for (int i = 0; i < points.size(); i++) {
            distance = get_distance(points[i]); 
            pq.push({distance, i});
            while (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> result;
        while (pq.empty() == false) {
            pair<int, int> p = pq.top();
            pq.pop();
            result.push_back(points[p.second]);
        }
        for (int i = 0; i < k; i++) {
            
        }
        return result;
    }
};
// quick select (hard to understand)
// Runtime: 156 ms, faster than 98.78 % of C++ online submissions for K Closest Points to Origin.
// Memory Usage : 57.1 MB, less than 85.48 % of C++ online submissions for K Closest Points to Origin.
class Solution {
private:
    int get_distance(vector<int>& point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        int left = 0;
        int right = points.size() - 1;
        int idx = points.size();
        while (idx != k) {
            // partition [left ~ right]
            // points in [left ~ idx]   is smaller than point[idx]
            // points in [idx  ~ right] is larger than point[idx]
            idx = partition(points, left, right);
            if (idx < k) {
                // [left ~ idx] has less than k elements and they all smaller than point[idx]
                // it means we need to find [idx ~ right]
                left = idx;
            } else {
                // [left ~ idx] has more than k elements and they all smaller than point[idx]
                // it means we need to find [left ~ idx - 1]
                right = idx - 1;
            }
        }

        // the first k elements is sorted
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    int partition(vector<vector<int>>& points, int left, int right)
    {
        // choose a pivot
        vector<int> pivot = choosePivot(points, left, right);
        // get the distance of pivot
        int distance_pivot = get_distance(pivot);
        while (left < right) {
            if (get_distance(points[left]) >= distance_pivot) {
                // if left is larger than pivot, swap with right
                // and decrease right since right will be larget than pivot
                points[left].swap(points[right]);
                right--;
            } else {
                // step left since it is smaller than pivot
                left++;
            }
        }
        // corner case (looks because left = right case is not checked?)
        if (get_distance(points[left]) < distance_pivot) {
            left++;
        }
        return left;
    }
    vector<int>& choosePivot(vector<vector<int>>& points, int left, int right) {
        // Choose a pivot element of the vector
        return points[left + (right - left) / 2];
    }
};