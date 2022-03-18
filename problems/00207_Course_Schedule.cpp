// https://www.cnblogs.com/grandyang/p/4484571.html
class Solution {
public:
	bool can_finish_dfs(vector<vector<int>> &graph, vector<int> &visit_map, int course_idx) {
		if (visit_map[course_idx] == 1) return true; // complete visit
		if (visit_map[course_idx] == -1) return false; // this course is the original course, loop found
		vector<int> next_courses = graph[course_idx];
		// mark this course as original course
		visit_map[course_idx] = -1;
		// dfs next courses of this course
		for (int i = 0; i < next_courses.size(); i++) {
			int next_course = next_courses[i];
			bool ret = can_finish_dfs(graph, visit_map, next_course);
			if (ret == false) {
				return false;
			}
		}
		// mark this course as visited
		visit_map[course_idx] = 1;
		return true;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// build graph
		// graph[i] = course[i], graph[i][j] = next course of course[i]
		vector<vector<int>> graph(numCourses, vector<int>());
		for (int i = 0; i < prerequisites.size(); i++) {
			int course  = prerequisites[i][0];
			int pre_req = prerequisites[i][1];
			graph[pre_req].push_back(course);
		}
		// build visit map
		// 1: visited
		// -1: conflict (original course)
		// 0: not visited
		vector<int> visit_map(numCourses, 0);
		for (int i = 0; i < numCourses; i++) {
			bool ret = can_finish_dfs(graph, visit_map, i);
			if (ret == false) {
				// a loop
				return false;
			}
		}
		return true;
	}
};

void test_207_Course_Schedule(void)
{
	Solution s;
	printf("%d\n", s.canFinish(2, vector<vector<int>>{{1, 0}}));
	printf("%d\n", s.canFinish(2, vector<vector<int>>{ {1, 0}, {0, 1}}));
}