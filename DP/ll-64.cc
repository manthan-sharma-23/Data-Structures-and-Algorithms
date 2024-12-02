#include <vector>

using namespace std;

class Solution {
public:
  int dfs(vector<vector<int>> &grid, int row, int col, int m, int n,
          vector<vector<int>> &memo) {
    if (row == m - 1 && col == n - 1) {
      return grid[row][col];
    }

    if (memo[row][col] != -1) {
      return memo[row][col];
    }

    int down = 1e6, right = 1e6;

    if (row + 1 < m)
      down = dfs(grid, row + 1, col, m, n, memo);

    if (col + 1 < n)
      right = dfs(grid, row, col + 1, m, n, memo);

    memo[row][col] = grid[row][col] + min(down, right);
    return memo[row][col];
  }

  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    return dfs(grid, 0, 0, m, n, memo);
  }
};

class BottomUpSolution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < n; i++) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return dp[m - 1][n - 1];
  }
};
