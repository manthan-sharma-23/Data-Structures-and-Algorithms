#include <climits>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  typedef pair<int, pair<int, int>> Node;
  int minimumEffortPath(vector<vector<int>> &heights) {
    int n = heights.size(), m = heights[0].size();

    const vector<pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!pq.empty()) {
      auto front = pq.top();
      pq.pop();

      int currEffort = front.first;
      int x = front.second.first;
      int y = front.second.second;

      if (x == n - 1 && y == m - 1) {
        return currEffort;
      }

      for (auto &direction : directions) {
        int nx = x + direction.first;
        int ny = y + direction.second;

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          int nextEffort =
              max(currEffort, abs(heights[nx][ny] - heights[x][y]));

          if (nextEffort < dist[nx][ny]) {
            dist[nx][ny] = nextEffort;
            pq.push({nextEffort, {nx, ny}});
          }
        }
      }
    }

    return -1;
  }
};
