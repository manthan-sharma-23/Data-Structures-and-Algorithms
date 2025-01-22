#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> Grid;
  const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  vector<vector<bool>> visited;
  int M, N;
  int count = 0;

  bool isValid(int r, int c) { return r >= 0 && c >= 0 && r < M && c < N; }

  int dfs(int row, int col) {

    int countu = 0;
    for (auto [dr, dc] : directions) {
      int nr = row + dr;
      int nc = col + dc;

      if (isValid(nr, nc) && Grid[nr][nc] > Grid[row][col]) {
        countu += dfs(nr, nc);
      }
    }

    return countu;
  }

  int countPaths(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    this->M = m, this->N = n;
    this->visited.resize(m, vector<bool>(n, false));
    this->Grid = grid;

    return dfs(0, 0);
  }
};