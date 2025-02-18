#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    const int n = s.length();

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int count = 0;

    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
      count++;
    }

    for (int i = 0; i < n; i++) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        count++;
      }
    }

    for (int length = 3; length <= n; length++) {
      for (int i = 0; i <= n - length; i++) {
        int j = i + length - 1;

        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          count++;
        }
      }
    }

    return count;
  }
};