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
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      auto job = Jobs[i - 1];

      int left = 0, right = i - 2, res = -1;

      while (left <= right) {
        int mid = left + (right - left) / 2;

        if (Jobs[mid][1] < job[0]) {
          res = mid;
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }

      dp[i] = max(dp[i - 1], job[2] + (res == -1 ? 0 : dp[res + 1]));
    }

    return dp[n];
  }
};