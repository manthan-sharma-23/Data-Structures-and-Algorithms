#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {

    int n = startTime.size();

    vector<vector<int>> Jobs(n);

    for (int i = 0; i < n; i++) {
      Jobs[i] = {
          startTime[i],
          endTime[i],
          profit[i],
      };
    }

    sort(
        Jobs.begin(), Jobs.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    vector<int> dp(n + 1, 0);

    int maxP = 0;

    for (int i = 1; i <= n; i++) {
      int P = Jobs[i - 1][2];
      int start = Jobs[i - 1][0];

      dp[i] = P;

      for (int cut = i - 2; cut > 0; cut--) {
        if (Jobs[cut - 1][1] <= start) {
          dp[i] = max(dp[i], P + dp[cut]);
        }
      }

      maxP = max(maxP, dp[i]);
    }

    return maxP;
  }
};