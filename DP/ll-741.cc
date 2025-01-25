
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    int n = grid.size();

    if (n == 1)
      return grid[0][0];

    if (grid[0][0] == -1 || grid[n - 1][n - 1] == -1)
      return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == -1)
          continue;

        if (i > 0)
          dp[i][j] = max(dp[i][j], dp[i - 1][j] + grid[i][j]);
        if (j > 0)
          dp[i][j] = max(dp[i][j], dp[i][j - 1] + grid[i][j]);
      }
    }

    int maxCherries1 = dp[n - 1][n - 1];

    int row = n - 1, col = n - 1;
    while (row != 0 || col != 0) {
      grid[row][col] = 0;

      int maxCherries = INT_MIN;
      int dr = 0, dc = 0;

      if (row > 0 && grid[row - 1][col] != -1 &&
          dp[row - 1][col] > maxCherries) {
        maxCherries = dp[row - 1][col];
        dr = -1;
        dc = 0;
      }

      if (col > 0 && grid[row][col - 1] != -1 &&
          dp[row][col - 1] > maxCherries) {
        maxCherries = dp[row][col - 1];
        dr = 0;
        dc = -1;
      }

      if (maxCherries == INT_MIN)
        return 0;

      row += dr;
      col += dc;
    }
    grid[0][0] = 0;

    dp.assign(n, vector<int>(n, INT_MIN));
    dp[n - 1][n - 1] = grid[n - 1][n - 1];

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] == -1)
          continue;

        if (i < n - 1)
          dp[i][j] = max(dp[i][j], dp[i + 1][j] + grid[i][j]);
        if (j < n - 1)
          dp[i][j] = max(dp[i][j], dp[i][j + 1] + grid[i][j]);
      }
    }

    int maxCherries2 = dp[0][0];
    return maxCherries1 + maxCherries2;
  }
};
