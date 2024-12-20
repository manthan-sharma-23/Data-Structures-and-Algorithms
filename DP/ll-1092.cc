#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.length(), m = str2.length();

    int dp[n + 1][m + 1];

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = i + j;
        } else if (str1[i - 1] == str2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }
    string result = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
      if (str1[i - 1] == str2[j - 1]) {
        result.push_back(str1[i - 1]);
        i--;
        j--;
      } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
          result.push_back(str2[j - 1]);
          j--;
        } else {
          result.push_back(str1[i - 1]);
          i--;
        }
      }
    }

    while (i > 0) {
      result.push_back(str1[i - 1]);
      i--;
    }

    while (j > 0) {
      result.push_back(str2[j - 1]);
      j--;
    }

    reverse(result.begin(), result.end());

    return result;
  }
};
