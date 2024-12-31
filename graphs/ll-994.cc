#include "vector"
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {

    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;

    bool visited[m + 1][n + 1];
    memset(visited, 0, sizeof(visited));

    int fresh = 0;

    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2)
          q.push({i, j});
        if (grid[i][j] == 1)
          fresh++;
      }
    }

    int time{0};

    while (!q.empty()) {
      int size = q.size();

      bool rotten = false;

      for (int i = 0; i < size; i++) {
        auto [x, y] = q.front();
        q.pop();

        for (auto &[dx, dy] : directions) {
          int nx = x + dx;
          int ny = y + dy;

          if (nx >= 0 && ny >= 0 && nx < m && ny < n && (grid[nx][ny] == 1)) {
            grid[nx][ny] = 2;
            q.push({nx, ny});
            fresh--;
            rotten = 1;
          }
        }
      }

      if (rotten)
        time++;
    }

    return fresh == 0 ? time : -1;
  }
};