#include <climits>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int n;
  int memo[101][101];
  const int large = 1e3;
  unordered_map<int, unordered_map<int, int>> subStringMap;

  int minConversionsToPalindrome(const string &s, int l, int r) {
    int changes = 0;
    while (l < r) {
      if (s[l++] != s[r--])
        changes++;
    }
    return changes;
  }

  int f(int i, int k) {
    if (k == 1)
      return memo[i][k] = subStringMap[i][n - 1];

    if (memo[i][k] != -1) {
      return memo[i][k];
    }

    int minChanges = large;

    for (int cut = i; cut < n - (k - 1); cut++) {
      int changes = subStringMap[i][cut] + f(cut + 1, k - 1);
      minChanges = min(minChanges, changes);
    }

    return memo[i][k] = minChanges;
  }

  int palindromePartition(string s, int k) {
    n = s.length();
    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        subStringMap[i][j] = minConversionsToPalindrome(s, i, j);
      }
    }

    return f(0, k);
  }
};

class TopDown {
  int minConversionsToPalindrome(const string &s, int l, int r) {
    int changes = 0;
    while (l < r) {
      if (s[l++] != s[r--])
        changes++;
    }
    return changes;
  }

public:
  int palindromePartition(string s, int k) {
    int n = s.length();
    const int large = 1e3;
    unordered_map<int, unordered_map<int, int>> subStringMap;

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        subStringMap[i][j] = minConversionsToPalindrome(s, i, j);
      }
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));

    for (int i = 0; i <= k; i++) {
      dp[i][i] = i;
    }

    for (int i = 0; i <= n; i++) {
      dp[i][0] = subStringMap[0][i];
      dp[i][1] = subStringMap[0][i];
    }

    for (int i = 0; i <= n; i++) {

      for (int group = 0; group <= i; group++) {

        if (group == i) {
          dp[i][group] = group;
          continue;
        }

        for (int cut = i; cut < n - (group - 1); i++) {
          dp[i][group] = min(dp[i][group], subStringMap[i][cut]);
        }
      }
    }
  }
};
