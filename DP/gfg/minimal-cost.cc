#include "vector"
#include <climits>
#include <cstdlib>

using namespace std;

class Solution {
public:
  int minimizeCost(int k, vector<int> &arr) {
    int n = arr.size();

    if (n <= 0)
      return 0;

    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
      for (int steps = 1; steps <= k && (i - steps) >= 0; steps++)
        dp[i] = min(dp[i], dp[i - steps] + abs(arr[i] - arr[i - steps]));
    }

    return dp[n - 1];
  }
};