#include <vector>

using namespace std;

class Solution {
public:
  int M, N;
  const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

  bool canCross(vector<vector<int>> &grid) {
    vector<vector<bool>> visited(M, vector<bool>(N, false));

    for (int j = 0; j < N; j++) {
      if (grid[0][j] == 0 && !visited[0][j]) {
        if (dfs(grid, 0, j, visited)) {
          return true;
        }
      }
    }

    return false;
  }

  bool dfs(vector<vector<int>> &grid, int row, int col,
           vector<vector<bool>> &visited) {
    if (row == M - 1) {
      return true;
    }

    visited[row][col] = true;

    for (auto [dr, dc] : directions) {
      int nr = row + dr, nc = col + dc;

      if (nr >= 0 && nc >= 0 && nr < M && nc < N && !visited[nr][nc] &&
          grid[nr][nc] == 0) {
        if (dfs(grid, nr, nc, visited)) {
          return true;
        }
      }
    }

    return false;
  }

  int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
    M = row, N = col;
    int n = cells.size();

    int day = 0;
    int l = 0, r = n;

    while (l <= r) {
      int mid = (l + r) / 2;

      vector<vector<int>> grid(row, vector<int>(col, 0));
      for (int i = 0; i < mid; i++) {
        grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
      }

      if (canCross(grid)) {
        day = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return day;
  }
};
