// link ->
// https://www.desiqna.in/16115/google-interview-problem-dynamic-programming-cities-october

#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using namespace std;

string maxEarning(vector<int> &a, vector<int> &b) {
  int n = a.size();
  const int A = 0, B = 1;

  vector<vector<int>> dp(n, vector<int>(2, INT_MAX));

  dp[0][A] = a[0];
  dp[0][B] = b[0];

  dp[1][A] = dp[0][A] + a[1];
  dp[1][B] = dp[0][B] + b[1];

  for (int i = 2; i < n; i++) {
    dp[i][A] = a[i] + max(dp[i - 1][A], dp[i - 2][B]);
    dp[i][B] = b[i] + max(dp[i - 1][B], dp[i - 2][A]);
  }

  string res;
  int row, col, rem;

  if (dp[n - 1][A] > dp[n - 1][B]) {
    row = A, col = n - 1, rem = dp[n - 1][A];
  } else {
    row = B, col = n - 1, rem = dp[n - 1][B];
  }

  while (col >= 0 && row >= 0 && row <= 1) {
    if (col == B) {
      if (rem == dp[col][B]) {
        res.push_back('B');
        rem -= b[col];
        col--;
      } else {
        res.push_back('T');
        col--, row = A;
      }
    } else {
      if (rem == dp[col][A]) {
        res.push_back('A');
        rem -= a[col];
        col--;
      } else {
        res.push_back('T');
        col--, row = B;
      }
    }
  }

  reverse(res.begin(), res.end());

  return res;
}