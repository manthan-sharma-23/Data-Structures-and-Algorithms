#include <climits>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
  int minDifference(vector<int> &arr) {
    // Your code goes here
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
    }
    sum /= 2;

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
      dp[i][0] = 1;

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        if (arr[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    int diff = INT_MAX;
    for (int i = 0; i <= sum; i++) {
      if (dp[n][i]) {
        diff = min(diff, sum - 2 * i);
      }
    }

    return diff;
  }
};
