#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
  int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &memo) {
    if (memo[i][j] != -1)
      return memo[i][j];
    if (i == j)
      return 0;
    int mini = 1e9;
    for (int k = i; k < j; k++) {
      int cost = cuts[j + 1] - cuts[i - 1];
      mini = min(cost + solve(cuts, i, k, memo) + solve(cuts, k + 1, j, memo),
                 mini);
    }

    return memo[i][j] = mini;
  }

  int minCost(int n, vector<int> &cuts) {
    int m = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> memo(m + 2, vector<int>(m + 2, -1));

    return solve(cuts, 1, m, memo);
  }
};

class TopDown {

public:
  int minCost(int n, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int m = cuts.size();

    int dp[m][m];
    memset(dp, 0, sizeof(dp));

    for (int i = m - 2; i >= 1; i++) {
      for (int j = i + 2; j < m; j++) {
        dp[i][j] = INT_MAX;

        for (int k = i; k <= j; k++) {
          int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] + dp[k + 1][j];
          dp[i][j] = min(dp[i][j], cost);
        }
      }
    }

    return dp[1][m - 1];
  }
};