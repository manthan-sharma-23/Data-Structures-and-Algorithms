// link ->
// https://www.desiqna.in/16208/microsoft-sde-oa-coding-questions-set-117-24th-dec-2023

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int maxLength(vector<int> &a) {
  int n = a.size();

  sort(a.begin(), a.end());

  vector<int> dp(n + 1, 1);

  dp[0] = 0;
  dp[1] = 1;
  unordered_map<int, int> mp;

  mp[a[0]] = 1;
  int mini = a[0];
  int maxi = dp[1];

  for (int i = 2; i <= n; i++) {

    int diff = 0;

    while (diff <= (a[i - 1] - mini)) {
      int el = a[i - 1] + diff;

      dp[i] = max(dp[i], 1 + dp[mp[el]]);

      diff++;
    }
    mp[a[i - 1]] = i;

    maxi = max(maxi, dp[i]);
    mini = min(mini, a[i - 1]);
  }
  return maxi;
}

int main() {
  vector<int> a = {1, 3, 4, 4, 4, 5};

  cout << maxLength(a) << endl;
}