#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();

    vector<int> dp(n + 1, INT_MIN);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      int maxi = arr[i - 1];
      for (int cut = i - 1; cut >= 0; cut--) {
        int len = i - cut;
        if (len > k)
          break;

        dp[i] = max(dp[i], maxi * len + dp[cut]);

        if (cut > 0)
          maxi = max(maxi, arr[cut - 1]);
      }
    }

    return dp[n];
  }
};