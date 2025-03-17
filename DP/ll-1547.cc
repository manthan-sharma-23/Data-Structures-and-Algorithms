#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  typedef long long ll;
  int minCost(int L, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(L);
    const int LARGE = 1e9;

    sort(cuts.begin(), cuts.end());
    int n = cuts.size();

    vector<vector<ll>> dp(n, vector<ll>(n, LARGE));

    for (int i = 0; i < n; i++) {
      dp[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        for (int k = i + 1; k < j; k++) {
          dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
        }

        if (dp[i][j] == LARGE)
          dp[i][j] = 0;
      }
    }

    return dp[0][n - 1];
  }
};
