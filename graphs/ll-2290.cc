#include <climits>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int minimumObstacles(vector<vector<int>> &grid) {
    typedef pair<int, pair<int, int>> Node;
    int m = grid.size(), n = grid[0].size();

    auto isValid = [m, n](int row, int col) -> bool {
      return row >= 0 && row < m && col >= 0 && col < n;
    };

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    int dist[m][n];
    memset(dist, INT_MAX, sizeof(dist));

    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!pq.empty()) {
      auto [currCost, currCoord] = pq.top();
      auto [row, col] = currCoord;
      pq.pop();

      if (currCost > dist[row][col])
        continue;

      if (row == m - 1 && col == n - 1) {
        return currCost;
      }

      for (auto &[dr, dc] : directions) {
        int nR = row + dr;
        int nC = col + dc;

        if (isValid(nR, nC)) {
          int cost = currCost + grid[nR][nC];
          if (cost < dist[nR][nC]) {
            dist[nR][nC] = cost;
            pq.push({cost, {nR, nC}});
          }
        }
      }
    }

    return -1;
  }
};