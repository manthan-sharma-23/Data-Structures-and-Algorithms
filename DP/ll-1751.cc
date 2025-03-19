#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxValue(vector<vector<int>> &events, int k) {

    int n = events.size();
    sort(
        events.begin(), events.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int j = 1; j <= k; j++) {
      for (int i = 1; i <= n; i++) {
        auto Event = events[i - 1];

        int left = 1, right = i - 1, res = -1;
        while (left <= right) {
          int mid = left + (right - left) / 2;

          if (events[mid][1] < Event[0]) {
            res = mid;
            left = ++mid;
          } else {
            right = --mid;
          }
        }

        dp[i][j] =
            max(dp[i - 1][j], Event[2] + res == -1 ? 0 : dp[res + 1][j - 1]);
      }
    }

    return dp[n][k];
  }
};