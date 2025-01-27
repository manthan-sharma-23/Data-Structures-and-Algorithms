#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numDistinct(string s, string T) {
    int n1 = s.length(), n2 = T.length();

    vector<vector<uint32_t>> dp(n2 + 1, vector<uint32_t>(n1 + 1, 0));

    for (int i = 0; i <= n1; i++) {
      dp[0][i] = 1;
    }

    for (int t = 1; t <= n2; t++) {
      for (int j = 1; j <= n1; j++) {
        dp[t][j] = dp[t][j - 1] + (T[t - 1] == s[j - 1] ? dp[t - 1][j - 1] : 0);
      }
    }

    return dp[n1][n2];
  }
};