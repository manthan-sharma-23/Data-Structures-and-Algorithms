#include <vector>

using namespace std;

class Solution {
public:
  int M, N;
  const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  bool isValid(int x, int y) { return x >= 0 && y >= 0 && x < M && y < N; }

  int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int row,
          int col) {
    if (dp[row][col] != -1) {
      return dp[row][col];
    }

    int max_length = 1;
    for (const auto &[dr, dc] : directions) {
      int nr = row + dr;
      int nc = col + dc;

      if (isValid(nr, nc) && matrix[nr][nc] > matrix[row][col]) {
        max_length = max(max_length, 1 + dfs(matrix, dp, nr, nc));
      }
    }

    return dp[row][col] = max_length;
  }

  int longestIncreasingPath(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
      return 0;

    M = matrix.size();
    N = matrix[0].size();
    vector<vector<int>> dp(M, vector<int>(N, -1));

    int max_path = 0;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        max_path = max(max_path, dfs(matrix, dp, i, j));
      }
    }

    return max_path;
  }
};
