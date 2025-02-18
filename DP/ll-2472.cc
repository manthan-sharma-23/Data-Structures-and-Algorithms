#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int maxPalindromes(string s, int k) {
    const int n = s.length();

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    vector<pair<int, int>> specialStrings;

    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
      if (k == 1)
        specialStrings.push_back({i, i});
    }

    for (int i = 0; i < n; i++) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        if (k == 2)
          specialStrings.push_back({i, i + 1});
      }
    }

    for (int length = 3; length <= n; length++) {
      for (int i = 0; i <= n - length; i++) {
        int j = i + length - 1;

        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          if (length >= k) {
            specialStrings.push_back({i, j});
          }
        }
      }
    }

    sort(
        specialStrings.begin(), specialStrings.end(),
        [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

    int lastJ = -1, count = 0;

    for (auto interval : specialStrings) {
      if (interval.first > lastJ) {
        lastJ = interval.second;
        count++;
      }
    }

    return count;
  }
};