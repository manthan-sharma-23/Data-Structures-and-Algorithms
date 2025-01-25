#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = grid[i][j];

        int minVal = INT_MAX;

        if (i > 0 && minVal > dp[i - 1][j]) {
          minVal = dp[i - 1][j];
        }
        if (j > 0 && minVal > dp[i][j - 1]) {
          minVal = dp[i][j - 1];
        }
        if (minVal != INT_MAX) {
          dp[i][j] += minVal;
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};
