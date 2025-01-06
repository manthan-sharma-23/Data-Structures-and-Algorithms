#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<vector<int>> &rooms, int node, vector<bool> &visited) {
    visited[node] = true;

    for (auto room : rooms[node]) {
      if (!visited[room]) {
        dfs(rooms, room, visited);
      }
    }
  }

  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();

    vector<bool> visited(n, false);

    dfs(rooms, 0, visited);

    for (auto b : visited) {
      if (!b)
        return false;
    }
    return true;
  }
};