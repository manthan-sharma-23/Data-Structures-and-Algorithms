#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  typedef pair<int, pair<int, int>> Node;

  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1])
      return -1;

    const vector<pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[0][0] = 1;
    pq.push({1, {0, 0}});

    while (!pq.empty()) {
      auto curr_node = pq.top();
      int currDist = curr_node.first;
      int currX = curr_node.second.first;
      int currY = curr_node.second.second;
      pq.pop();

      if (currX == n - 1 && currY == n - 1)
        return currDist;

      for (const auto &direction : directions) {
        int dx = direction.first;
        int dy = direction.second;

        int nx = currX + dx;
        int ny = currY + dy;

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 &&
            currDist + 1 < dist[nx][ny]) {
          dist[nx][ny] = currDist + 1;
          pq.push({dist[nx][ny], {nx, ny}});
        }
      }
    }

    return -1;
  }
};
