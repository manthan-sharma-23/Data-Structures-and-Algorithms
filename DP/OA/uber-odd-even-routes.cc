#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isOdd(int n) { return n % 2 != 0; }

pair<int, int> numOddEvenRoutes(int A[], int B[], int n) {
  int dp[n][2];
  const int a = 0, b = 1;

  //    store odd routes in the dp array
  //    dp[i][x] indicates maximum number of odd routes till the ith index of x
  //    array (A or B);

  dp[0][a] = isOdd(A[0]);
  dp[0][b] = isOdd(B[0]);

  if (n == 0)
    return {0, 0};

  int routes = 2;
  for (int i = 1; i < n; i++) {

    // for A[i]
    if (isOdd(A[i])) {
      dp[i][a] = routes - (dp[i - 1][a] + dp[i - 1][b]);
    } else {
      dp[i][a] = dp[i - 1][a] + dp[i - 1][b];
    }

    //  for B[i]
    if (isOdd(B[i])) {
      dp[i][b] = routes - (dp[i - 1][a] + dp[i - 1][b]);
    } else {
      dp[i][b] = dp[i - 1][a] + dp[i - 1][b];
    }
    routes *= 2;
  }

  int maxOddCount = dp[n - 1][a] + dp[n - 1][b];
  int maxEvenCount = routes - maxOddCount;

  return {maxOddCount, maxEvenCount};
}

int main() {
  int a[] = {1, 3, 5};
  int b[] = {7, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);

  auto result = numOddEvenRoutes(a, b, n);
  cout << "Odd Journeys: " << result.first << endl;
  cout << "Even Journeys: " << result.second << endl;
}