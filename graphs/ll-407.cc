#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  bool isValid(int row, int col, int M, int N) {
    return row >= 0 && col >= 0 && row < M && col < N;
  }

  int getMinBoundaryValue(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    int minValue = INT_MAX;

    for (int i = 0; i < m; ++i) {
      minValue = min(minValue, grid[i][0]);
      minValue = min(minValue, grid[i][n - 1]);
    }

    for (int j = 0; j < n; ++j) {
      minValue = min(minValue, grid[0][j]);
      minValue = min(minValue, grid[m - 1][j]);
    }

    return minValue;
  }

  int trapRainWater(vector<vector<int>> &heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();
    typedef pair<int, pair<int, int>> Node;

    if (m == 0 || n == 0)
      return 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      pq.push({heightMap[i][0], {i, 0}});
      pq.push({heightMap[i][n - 1], {i, n - 1}});
      visited[i][0] = visited[i][n - 1] = true;
    }

    for (int j = 0; j < n; ++j) {
      pq.push({heightMap[0][j], {0, j}});
      pq.push({heightMap[m - 1][j], {m - 1, j}});
      visited[0][j] = visited[m - 1][j] = true;
    }

    int volume = 0;

    while (!pq.empty()) {
      auto [height, coord] = pq.top();
      pq.pop();
      auto [row, col] = coord;

      for (auto [dr, dc] : directions) {
        int nr = row + dr, nc = col + dc;

        if (isValid(nr, nc, m, n) && !visited[nr][nc]) {
          visited[nr][nc] = true;
          volume += max(height - heightMap[nr][nc], 0);
          pq.push({max(height, heightMap[nr][nc]), {nr, nc}});
        }
      }
    }

    return volume;
  }
};
