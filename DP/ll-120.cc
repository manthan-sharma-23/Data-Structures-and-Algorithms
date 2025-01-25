#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();

    vector<int> dp(n, INT_MAX);

    dp[0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < triangle[i].size(); j++) {
        dp[i] = min(dp[i], dp[i - 1] + triangle[i][j]);
      }
    }

    return dp[n - 1];
  }
};