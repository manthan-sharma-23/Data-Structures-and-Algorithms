#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int longestIdealString(string s, int k) {
    int n = s.length();

    if (n <= 1)
      return n;

    vector<int> dp(26, 0);

    int maxL = 0;

    dp[s[0] - 'a'] = 1;

    for (int i = 1; i < n; i++) {
      int t = 0;
      for (int d = 0; d <= k; d++) {
        t = max(t, 1 + dp[(s[i] + d) - 'a']);
        t = max(t, 1 + dp[(s[i] - d) - 'a']);
      }

      dp[s[i] - 'a'] = max(dp[s[i] - 'a'], t);
      maxL = max(maxL, dp[s[i] - 'a']);
    }

    return maxL;
  }
};