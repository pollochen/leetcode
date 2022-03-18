// https://www.cnblogs.com/grandyang/p/4484571.html
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> result;
		// build graph and courses need pre-requisites
		// graph[i] = course[i], graph[i][j] = next course of course[i]
		vector<vector<int>> graph(numCourses, vector<int>());
		vector<int> courses_in(numCourses, 0);
		for (int i = 0; i < prerequisites.size(); i++) {
			int course = prerequisites[i][0];
			int pre_req = prerequisites[i][1];
			graph[pre_req].push_back(course);
			courses_in[course]++;
		}

		// build queue and push course idx which doesn't need pre-requisite
		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (courses_in[i] == 0) {
				q.push(i);
			}
		}
		// start to traverse queue
		while (q.empty() == false) {
			int course_idx = q.front(); q.pop();

			// each node in the queue doesn't need pre-quesisite courses
			// that means no nodes in queue will traverse to it
			// so we can publish it anyway
			result.push_back(course_idx);

			// get next courses of this course and push them into queue
			vector<int> next_courses = graph[course_idx];
			for (int i = 0; i < next_courses.size(); i++) {
				int next_course = next_courses[i];
				courses_in[next_course]--; // we have visit this pre-quesisite course, minus 1
				if (courses_in[next_course] == 0) {
					q.push(next_course); // only push this course when it doesn't need pre-quesisite courses
				}
			}
		}

		if (result.size() != numCourses) result.clear();

		return result;
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

void test_210_Course_Schedule_II(void)
{
	Solution s;
	print_vector_int(s.findOrder(2, vector<vector<int>>{ {1, 0}}));
	print_vector_int(s.findOrder(4, vector<vector<int>>{ {1, 0}, { 2, 0 }, { 3, 1 }, { 3,2 }}));
	print_vector_int(s.findOrder(2, vector<vector<int>>{ {1, 0}, { 0, 1 }}));
	print_vector_int(s.findOrder(1, vector<vector<int>>{ }));
}