#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int numDecodings(string s) {
    int n = s.length();

    if (s[0] == '0')
      return 0;

    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = s[0] != '0' ? 1 : 0;

    for (int i = 2; i <= n; i++) {
      // single digit
      char d = s[i - 1];

      if (d != '0') {
        dp[i] += dp[i - 1];
      }

      int num = stoi(s.substr(i - 2, 2));

      if (num >= 10 && num <= 26)
        dp[i] += dp[i - 2];
    }

    return dp[n];
  }
};