// BFS
// Runtime: 16 ms, faster than 32.77% of C++ online submissions for Keys and Rooms.
// Memory Usage: 10.7 MB, less than 24.39% of C++ online submissions for Keys and Rooms.
class Solution {
public:
    void visit(int room, queue<int> &que, vector<vector<int>>& rooms, vector<bool> &visited)
    {
        // mark room as visited
        visited[room] = true;
        // visit room x
        vector<int> keys = rooms[room];
        for (int i = 0; i < keys.size(); i++) {
            int key = keys[i];
			// only use the key when the room is not visited and the key is not for the room
            if ((visited[key] == false) && (room != key)) {
                que.push(key);            
            }
        }                
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        queue<int> que;
        
        visit(0, que, rooms, visited);
        
        while (que.empty() == false) {
            int room = que.front();
            que.pop();
            visit(room, que, rooms, visited);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == false) return false;
        }
        return true;
    }
};