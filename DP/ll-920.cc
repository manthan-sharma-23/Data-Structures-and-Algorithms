
#include <vector>

using namespace std;

class Solution {
public:
  int numMusicPlaylists(int n, int goal, int k) {
    const int MOD = 1e9 + 7;

    vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1, 0));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= goal; j++) {

        dp[i][j] = ((n - i) * dp[i - 1][j - 1]) % MOD;
        if (i > k)
          dp[i][j] = (dp[i][j] + ((i - k) * dp[i][j - 1] % MOD)) % MOD;
      }
    }

    return dp[n][goal];
  }
};