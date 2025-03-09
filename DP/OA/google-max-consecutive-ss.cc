/*

Given array of positive integers of length n (n<=100000)

(a[i]<=100000)
You have to maximize the consecutive integers count in array (Order doesn't
matter) Only operation you are allowed to with array elements is to make ai=ai+1
i.e increase the element by one  OR ai=ai+0 i.e do nothing with element for all
0<=i<n E.gInput n=9 arr:1 1 3 4 6 6 6 8 10 ans = 5 Explanation: You can
transform the array to 1 1 4 5 6 7 6 8 10 maximum consecutive length is 5 with
elements 4,5,6,7,8.

*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxConsecutvies(vector<int> &a) {
  int n = a.size();
  sort(a.begin(), a.end());

  vector<vector<int>> dp(n, vector<int>(2, 0));

  dp[0][1] = dp[0][0] = 1;
  int ans = 1;

  for (int i = 1; i < n; i++) {
    // +0
    {
      if (a[i] == a[i - 1] + 1) {
        dp[i][0] = dp[i - 1][0] + 1;
      } else if (a[i] == a[i - 1] + 2) {
        dp[i][0] = dp[i - 1][1] + 1;
      } else {
        dp[i][0] = 1;
      }

      ans = max(ans, dp[i][0]);
    }

    // +1
    {
      if (a[i] + 1 == a[i - 1] + 1) {
        dp[i][1] = dp[i - 1][0] + 1;
      } else if (a[i] + 1 == a[i - 1] + 2) {
        dp[i][1] = dp[i - 1][1] + 1;
      } else {
        dp[i][1] = 1;
      }

      ans = max(ans, dp[i][1]);
    }
  }

  return ans;
}

int main() {
  vector<int> a = {1, 1, 3, 4, 6, 6, 6, 8, 10};

  cout << maxConsecutvies(a) << endl;
}
