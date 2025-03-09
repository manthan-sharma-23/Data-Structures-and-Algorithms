/*
Problem Asked :- Given two arrays A and B both of size “N” ; find the number of
pair of subsets {S1,S2} ; such that max(S1)>=max(S2) ; where “S1”-> subset from
Array A and “S2” -> subset from Array B

1<=N<=100000

1<=A[i],B[i]<=100000

Find the final answer module 1e9 + 7.
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int maxSubsets(vector<int> &a, vector<int> b) {

  int n = a.size();
  const int MOD = 1e9 + 7;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = 0;

  int i = 0, j = 0;

  while (i < n && j < n) {
    if (a[i] >= b[j]) {
      int len = n - i;
      int counta = pow(2, len) - (len > 1 ? pow(2, (len - 1)) : 0);
      int countb = pow(2, j + 1);
      ans += (counta * countb) % MOD;
      ans %= MOD;
      j++;
    } else
      i++;
  }

  return ans;
}

int main() {
  vector<int> a = {1, 2, 3, 4};
  vector<int> b = {3, 4, 7, 8};

  cout << maxSubsets(a, b) << endl;
}