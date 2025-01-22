#include <climits>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  int minimumTime(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    typedef pair<int, pair<int, int>> Node;

    function<bool(int, int)> isValid = [m, n](int r, int c) -> bool {
      return r >= 0 && c >= 0 && r < m && c < n;
    };

    vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, {0, 0}});

    distance[0][0] = 0;

    while (!pq.empty()) {
      auto [currTime, currNode] = pq.top();
      auto [row, col] = currNode;
      pq.pop();

      if (currTime > distance[row][col])
        continue;

      if (row == m - 1 && col == n - 1) {
        return currTime;
      }

      for (auto &[dr, dc] : directions) {
        int nr = row + dr;
        int nc = col + dc;

        if (isValid(nr, nc)) {
          int wt = currTime;
          int wait = grid[nr][nc] - currTime;
          if (wait > 0) {
            wt += wait % 2 == 0 ? wait + 1 : wait;
          } else {
            wt++;
          }

          if (row == 0 && col == 0 && wt > 1) {
            continue;
          }

          if (distance[nr][nc] > wt) {
            distance[nr][nc] = wt;
            pq.push({wt, {nr, nc}});
          }
        }
      }
    }

    return -1;
  }
};