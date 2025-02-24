// link ->
// https://www.desiqna.in/15065/cisco-ideathon-coding-oa-2023-solution-kumar-monica-and-jaey

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

//  O(n^2)

int minMeals(vector<int> &values, int k, int m) {
  int n = values.size();

  vector<int> dp(n + 1, INT_MAX);

  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    int big = values[i - 1], small = values[i - 1];
    for (int cut = i - 1; cut >= 0; cut--) {
      if (big - small <= m && (i - cut) >= k) {
        dp[i] = min(dp[i], 1 + dp[cut]);
      }
      if (cut > 0) {
        big = max(big, values[cut - 1]);
        small = min(small, values[cut - 1]);
      }
    }
  }

  return dp[n] == INT_MAX ? -1 : dp[n];
}