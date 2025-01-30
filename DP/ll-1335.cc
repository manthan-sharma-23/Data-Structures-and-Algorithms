#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int n;
  int f(vector<int> &jobs, int d, int index, vector<vector<int>> &dp) {

    if (d == 0 && index == n)
      return 0;
    if (d == 0 || index == n)
      return INT_MAX;
    if (dp[index][d] != -1)
      return dp[index][d];

    int res = INT_MAX, maxJob = jobs[index];

    for (int i = index; i <= n - d; ++i) {
      maxJob = max(maxJob, jobs[i]);
      int next = f(jobs, d - 1, i + 1, dp);

      if (next != INT_MAX) {
        res = min(res, maxJob + next);
      }
    }

    return dp[index][d] = res;
  }

  int minDifficulty(vector<int> &jobDifficulty, int d) {
    n = jobDifficulty.size();
    if (n < d)
      return -1;

    vector<vector<int>> dp(n, vector<int>(d + 1, -1));
    return f(jobDifficulty, d, 0, dp);
  }
};
