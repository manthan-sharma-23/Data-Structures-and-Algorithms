#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
      dp[0][i] = matrix[0][i];

    for (int i = 1; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = matrix[i][j];

        int minVal = dp[i - 1][j];

        if (j > 0) {
          minVal = min(minVal, dp[i - 1][j - 1]);
        }

        if (j < n - 1) {
          minVal = min(minVal, dp[i - 1][j + 1]);
        }

        dp[i][j] += minVal;
      }
    }

    return *min_element(dp[m - 1].begin(), dp[m - 1].end());
  }
};