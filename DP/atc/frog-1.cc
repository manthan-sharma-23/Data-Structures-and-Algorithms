#include <climits>
#include <cstdlib>
#include <vector>

using namespace std;

int frog1(int n, vector<int> &h) {
  vector<int> dp(n, INT_MAX);

  if (n < 1)
    return 0;

  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);

  for (int i = 2; i < n; i++) {
    dp[i] =
        min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]);
  }

  return dp[n - 1];
}

int frog2(int n, int k, vector<int> &h) {
  vector<int> dp(n, INT_MAX);

  if (n < 1)
    return 0;

  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);

  for (int i = 2; i < n; i++) {
    for (int steps = 1; steps <= k; steps++) {
      if (i - steps >= 0) {
        dp[i] = min(dp[i], dp[i - steps] + abs(h[i] - h[i - steps]));
      }
    }
  }

  return dp[n - 1];
}