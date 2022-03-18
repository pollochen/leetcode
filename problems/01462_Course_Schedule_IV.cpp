class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> map(numCourses, vector<bool>(numCourses, false)); // Defaults to zero initial value
        vector<bool> result;

        // init map
        for (int i = 0; i < numCourses; i++) {
            map[i][i] = true;
        }
        // assign map to init value
        for (int i = 0; i < prerequisites.size(); i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            map[x][y] = true;
        }

        // Floyd Warshall Algorithm
        for (int k = 0; k < numCourses;k++) {
            for (int i = 0; i < numCourses;i++) {
                for (int j = 0; j < numCourses;j++) {
                    if (i == j) continue;
                    bool val_map = map[i][j];
                    bool val_ik = map[i][k];
                    bool val_kj = map[k][j];
                    map[i][j] = val_map | (val_ik & val_kj);
                }
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            result.push_back(map[queries[i][0]][queries[i][1]]);
        }
        return result;
    }
};