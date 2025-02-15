/*
link ->
https://www.desiqna.in/10567/barclays-sde-coding-oa-questions-and-solutions-set-8-2022-dp

*/

#include <cmath>
#include <iostream>

using namespace std;

int maxCompensation(int easy[], int hard[], int n) {
  int e = 0, h = 1;
  if (n == 0)
    return 0;
  if (n == 1)
    return max(easy[0], hard[0]);

  int dp[2][n];

  dp[e][0] = easy[0], dp[h][0] = hard[0];

  dp[e][1] = easy[1] + hard[0], dp[h][1] = hard[1];

  for (int i = 2; i < n; i++) {
    dp[e][i] = easy[i] + max(dp[e][i - 1], dp[h][i - 1]);
    dp[h][i] = hard[i] + max(dp[e][i - 2], dp[h][i - 2]);
  }

  return max(dp[e][n - 1], dp[h][n - 1]);
}

int main() {

  int n;
  cin >> n;

  int e[n], h[n];

  for (int i = 0; i < n; i++)
    cin >> e[i];

  for (int i = 0; i < n; i++)
    cin >> h[i];

  cout << "max : " << maxCompensation(e, h, n) << endl;
}