// https://www.cnblogs.com/grandyang/p/5727892.html
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int> pq; // maximum element in first position
		int n = matrix.size(); 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				pq.push(matrix[i][j]);
				if (pq.size() > k) {
					// we just want to have k smallest elements
					pq.pop();
				}
			}
		}
		return pq.top(); // maximum element is in first position
	}
};

void test_378_Kth_Smallest_Element_in_a_Sorted_Matrix(void)
{
	Solution s;
	printf("%d\n", s.kthSmallest(vector<vector<int>>{ {1, 5, 9}, { 10, 11, 13 }, { 12, 13, 15 }}, 8));
	printf("%d\n", s.kthSmallest(vector<vector<int>>{ {-5}}, 1));
}