/*

link ->
https://www.desiqna.in/11154/uber-hard-dynamic-programming-coding-questions-solutions

-> There are two arrays , 'B' and 'C' ; size of both the arrays is 'N' ;

-> At each index you are supposed to pick up an element either from array 'C' or
array 'B'

->You have to maximize the final sum of all elements

->Condition : You cannot select 3 or more than 3 element consecutively from the
same array.

*/

#include <algorithm>
#include <iostream>

using namespace std;

int maxSum(int B[], int C[], int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return max(B[0], C[0]);

  int dp[n][2][2];

  dp[0][0][0] = dp[0][0][1] = B[0];
  dp[0][1][0] = dp[0][1][1] = C[0];

  if (n > 1) {
    dp[1][0][0] = B[1] + B[0];
    dp[1][0][1] = B[1] + C[0];
    dp[1][1][1] = C[1] + C[0];
    dp[1][1][0] = C[1] + B[0];
  }

  if (n > 2) {
    dp[2][0][0] = B[2] + B[1] + C[0];
    dp[2][0][1] = B[2] + C[1] + max(C[0], B[0]);
    dp[2][1][1] = C[2] + C[1] + B[0];
    dp[2][1][0] = C[2] + B[1] + max(C[0], B[0]);
  }

  for (int i = 3; i < n; i++) {
    dp[i][0][0] = B[i] + B[i - 1] + max(dp[i - 2][1][1], dp[i - 2][1][0]);
    dp[i][1][1] = C[i] + C[i - 1] + max(dp[i - 2][0][0], dp[i - 2][0][1]);
    dp[i][1][0] = C[i] + B[i - 1] +
                  max({dp[i - 2][0][1], dp[i - 2][1][1], dp[i - 2][1][0]});
    dp[i][0][1] = B[i] + C[i - 1] +
                  max({dp[i - 2][1][0], dp[i - 2][0][0], dp[i - 2][0][1]});
  }

  return max(
      {dp[n - 1][1][1], dp[n - 1][1][0], dp[n - 1][0][1], dp[n - 1][0][0]});
}

int main() {
  int B[] = {5, 4, 3, 22};    // Added a missing element for n=5
  int C[] = {10, 10, 10, 33}; // Added a missing element for n=5
  int n = sizeof(B) / sizeof(B[0]);
  cout << "Max Sum: " << maxSum(B, C, n) << endl;
  return 0;
}
