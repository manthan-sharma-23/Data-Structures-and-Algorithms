#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    int n = profit.size();
    vector<vector<int>> jobs(n);

    for (int i = 0; i < n; i++) {
      jobs[i] = {startTime[i], endTime[i], profit[i]};
    }

    sort(
        jobs.begin(), jobs.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      auto &job = jobs[i - 1];
      int currProfit = job[2];

      int l = 0, r = i - 1, nextJobIndex = 0;
      while (l < r) {
        int mid = (l + r + 1) / 2;
        if (jobs[mid][1] <= job[0]) {
          nextJobIndex = mid + 1;
          l = mid;
        } else {
          r = mid - 1;
        }
      }

      currProfit += dp[nextJobIndex];
      dp[i] = max(dp[i - 1], currProfit);
    }
    return dp[n];
  }
};
