#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>
using namespace std;

string calcLongestString(string &s, int k) {
  int n = s.length();
  vector<int> dp(n, 1);

  for (int i = 1; i < n; i++) {
    if (s[i] - s[i - 1] <= k) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = 1;
    }
  }

  int maxL = 0, idx = -1;

  for (int i = 0; i < n; i++) {
    if (dp[i] > maxL) {
      maxL = dp[i];
      idx = i;
    }
  }

  string res = "";
  res.push_back(s[idx]);
  while (idx > 0 && dp[idx] == dp[idx - 1] + 1) {
    res.push_back(s[--idx]);
  }

  reverse(res.begin(), res.end());

  return res;
}