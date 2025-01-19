#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  const vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();
    typedef pair<int, pair<int, int>> Node;

    auto isValid = [n](int row, int col) {
      return row >= 0 && col >= 0 && row < n && col < n;
    };

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<vector<int>> timeTaken(n, vector<int>(n, INT_MAX));

    pq.push({grid[0][0], {0, 0}});

    while (!pq.empty()) {
      auto [time, coord] = pq.top();
      auto [row, col] = coord;
      pq.pop();

      if (row == n - 1 && col == n - 1) {
        return time;
      }

      for (auto [dr, dc] : directions) {
        int nr = row + dr;
        int nc = col + dc;

        if (isValid(nr, nc)) {
          int new_time = max(time, grid[nr][nc]);

          if (timeTaken[nr][nc] > new_time) {
            timeTaken[nr][nc] = new_time;
            pq.push({new_time, {nr, nc}});
          }
        }
      }
    }

    return -1;
  }
};