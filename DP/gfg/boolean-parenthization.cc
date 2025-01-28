#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countTotalWays(string &s, int i, int j, bool isTrue,
                     vector<vector<vector<int>>> &dp) {
    if (i > j)
      return 0;
    if (i == j) {
      if (isTrue)
        return s[i] == 'T';
      else
        return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
      return dp[i][j][isTrue];

    int ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
      int leftTrue = countTotalWays(s, i, k - 1, true, dp);
      int leftFalse = countTotalWays(s, i, k - 1, false, dp);
      int rightTrue = countTotalWays(s, k + 1, j, true, dp);
      int rightFalse = countTotalWays(s, k + 1, j, false, dp);

      if (s[k] == '&') {
        if (isTrue)
          ways += leftTrue * rightTrue;
        else
          ways += leftTrue * rightFalse + leftFalse * rightTrue +
                  leftFalse * rightFalse;
      } else if (s[k] == '|') {
        if (isTrue)
          ways += leftTrue * rightTrue + leftTrue * rightFalse +
                  leftFalse * rightTrue;
        else
          ways += leftFalse * rightFalse;
      } else if (s[k] == '^') {
        if (isTrue)
          ways += leftTrue * rightFalse + leftFalse * rightTrue;
        else
          ways += leftTrue * rightTrue + leftFalse * rightFalse;
      }
    }

    return dp[i][j][isTrue] = ways;
  }

  int countWays(string s) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(n, vector<int>(2, -1)));
    return countTotalWays(s, 0, n - 1, true, dp);
  }
};
