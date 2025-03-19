#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  typedef long long ll;
  long long maxTaxiEarnings(int L, vector<vector<int>> &rides) {
    int n = rides.size();
    vector<ll> dp(n + 1, 0);

    sort(
        rides.begin(), rides.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    for (int i = 1; i <= n; i++) {
      auto Ride = rides[i - 1];

      ll profit = Ride[1] - Ride[0] + Ride[2];

      int l = 0, r = i - 2, res = -1;

      while (l <= r) {

        int mid = l + (r - l) / 2;

        if (rides[mid][1] <= Ride[0])
          l = mid + 1, res = mid;
        else
          r = mid - 1;
      }

      dp[i] = max(dp[i - 1], profit + (res == -1 ? 0 : dp[res + 1]));
    }

    return dp[n];
  }
};