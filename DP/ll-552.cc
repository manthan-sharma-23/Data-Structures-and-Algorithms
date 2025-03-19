#include <vector>

using namespace std;

class Solution {
public:
  int checkRecord(int n) {
    vector<vector<vector<long long>>> dp(
        n + 1, vector<vector<long long>>(2, vector<long long>(3, 0)));
    const int MOD = 1e9 + 7;

    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    dp[0][1][0] = 1;

    for (int i = 1; i <= n; i++) {

      dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;

      dp[i][0][1] = dp[i - 1][0][0];
      dp[i][0][2] = dp[i - 1][0][1];
      dp[i][1][1] = dp[i - 1][1][0];
      dp[i][1][2] = dp[i - 1][1][1];

      dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
      dp[i][1][0] =
          (dp[i][1][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) %
          MOD;
    }
    int result = 0;
    for (int a = 0; a < 2; a++) {
      for (int l = 0; l < 3; l++) {
        result = (result + dp[n][a][l]) % MOD;
      }
    }

    return result;
  }
};