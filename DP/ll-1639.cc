#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  typedef uint64_t u64;
  const int MOD = 1e9 + 7;
  int numWays(vector<string> &words, string target) {
    int n = words.size(), ncol = words[0].length();
    int t = target.length();

    vector<vector<u64>> freq(ncol, vector<u64>(26, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < words[i].size(); j++) {
        freq[j][words[i][j] - 'a']++;
      }
    }

    vector<vector<u64>> dp(ncol + 1, vector<u64>(t + 1, 0));

    for (int i = 0; i <= ncol; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= ncol; i++) {
      for (int j = 1; j <= t; j++) {

        dp[i][j] = dp[i - 1][j];

        dp[i][j] =
            (dp[i][j] + dp[i - 1][j - 1] * freq[i - 1][target[j - 1] - 'a']) %
            MOD;
      }
    }

    return dp[ncol][t];
  }
};
