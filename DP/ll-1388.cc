#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> Slices;
  vector<vector<int>> dp;

  int solve(int i, int end, int k) {
    if (k == 0 || i > end)
      return 0;

    if (dp[i][k] != -1)
      return dp[i][k];

    int take = Slices[i] + solve(i + 2, end, k - 1);
    int notTake = solve(i + 1, end, k);

    return dp[i][k] = max(take, notTake);
  }

  int maxSizeSlices(vector<int> &slices) {
    int n = slices.size();
    Slices = slices;

    dp.assign(n, vector<int>(n / 3 + 1, -1));
    int case1 = solve(0, n - 2, n / 3);

    dp.assign(n, vector<int>(n / 3 + 1, -1));
    int case2 = solve(1, n - 1, n / 3);

    return max(case1, case2);
  }
};
