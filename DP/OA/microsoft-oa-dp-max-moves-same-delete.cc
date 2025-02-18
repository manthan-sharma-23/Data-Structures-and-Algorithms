// link ->
// https://www.desiqna.in/15592/microsoft-oa-sde-1-dp-freshers-hiring-43-lac-ctc

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int solution(vector<int> &a) {
  int n = a.size();
  if (n < 2)
    return 0;

  int s1 = a[0] + a[1], s2 = a[n - 1] + a[n - 2], s3 = a[0] + a[n - 1];

  vector<vector<map<int, int>>> dp(n, vector<map<int, int>>(n));

  // len = 2
  for (int i = 0; i < n - 1; i++) {
    int s = a[i] + a[i + 1];
    if (s == s1 || s == s2 || s == s3)
      dp[i][i + 1][s] = 1;
  }

  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;

      if (a[i] + a[j] == s1 || a[i] + a[j] == s2 || a[i] + a[j] == s3) {
        int prev = 0;
        for (const auto &it : dp[i + 1][j - 1]) {
          prev = max(prev, it.second);
        }
        dp[i][j][a[i] + a[j]] = 1 + prev;
      }
      if (i + 1 < j && (a[i] + a[i + 1] == s1 || a[i] + a[i + 1] == s2 ||
                        a[i] + a[i + 1] == s3)) {
        int prev = 0;
        for (const auto &it : dp[i + 2][j]) {
          prev = max(prev, it.second);
        }
        dp[i][j][a[i] + a[i + 1]] = 1 + prev;
      }
      if (j - 1 > i && (a[j] + a[j - 1] == s1 || a[j] + a[j - 1] == s2 ||
                        a[j] + a[j - 1] == s3)) {
        int prev = 0;
        for (const auto &it : dp[i][j - 2]) {
          prev = max(prev, it.second);
        }
        dp[i][j][a[j] + a[j - 1]] = 1 + prev;
      }
    }
  }

  int maxScore = 0;

  for (auto it : dp[0][n - 1]) {
    maxScore = max(it.second, maxScore);
  }

  return maxScore;
}

int main() {
  vector<int> a = {1, 1, 2, 3, 1, 2, 2, 1, 1, 2};
  cout << solution(a) << endl;
}
