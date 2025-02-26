#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int minCost(vector<int> &A, vector<int> &B, int N) {
  const int a = 0, b = 1;
  vector<vector<int>> dp(N, vector<int>(2, INT_MAX));

  dp[a][0] = A[0];

  for (int i = 1; i < N; i++) {
    dp[a][i] = A[i] + min(dp[a][i - 1], dp[b][i - 1]);

    if (i > 1)
      dp[b][i] = B[i] + B[i - 1] + min(dp[a][i - 2], dp[b][i - 2]);
    else
      dp[b][i] = B[i] + B[i - 1];
  }

  return min(dp[a][N - 1], dp[b][N - 1]);
}

int main() {
  vector<int> A = {3, 5, 2, 1, 9};
  vector<int> B = {1, 1, 10, 5, 3};

  cout << minCost(A, B, A.size()) << endl;
}