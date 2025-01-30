#include <vector>

using namespace std;

class Solution {
public:
  int M, N;

  const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  bool isValid(int row, int col) {
    return row >= 0 && col >= 0 && row < M && col < N;
  }

  int dfs(const vector<vector<int>> &grid, int row, int col,
          vector<vector<bool>> &visited) {

    int count = grid[row][col];
    visited[row][col] = true;

    for (const auto &[dr, dc] : directions) {
      int nr = row + dr, nc = col + dc;

      if (isValid(nr, nc) && !visited[nr][nc] && grid[nr][nc] > 0) {
        count += dfs(grid, nr, nc, visited);
      }
    }

    return count;
  }

  int findMaxFish(vector<vector<int>> &grid) {
    M = grid.size(), N = grid[0].size();

    int fishes = 0;

    vector<vector<bool>> visited(M, vector<bool>(N, 0));

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (!visited[i][j] && grid[i][j] > 0) {
          int fish_count = dfs(grid, i, j, visited);

          fishes = max(fish_count, fishes);
        }
      }
    }

    return fishes;
  }
};