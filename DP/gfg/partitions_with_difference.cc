#include <vector>

using namespace std;

class Solution {
public:
  int countPartitions(vector<int> &arr, int d) {
    int n = arr.size();
    int sum{0};
    for (auto num : arr)
      sum += num;

    if ((sum + d) % 2 != 0 || sum < d) {
      return 0;
    }

    int find = (sum + d) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(find + 1, 0));
    for (int i = 0; i <= n; i++)
      dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= find; j++) {
        if (arr[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n][find];
  };
};
