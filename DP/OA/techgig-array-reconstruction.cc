#include <charconv>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

bool isStringValid(string a, int k) {
  if (a[0] == '0' || a.empty())
    return false;

  int number;
  from_chars(a.data(), a.data() + a.size(), number);

  return number <= k && number >= 1;
}

int numWays(string &s, int K) {
  int n = s.length();

  vector<int> dp(n + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int c = i - 1; c >= 0; c--) {
      if (isStringValid(s.substr(c, i - c), K)) {
        dp[i] += dp[c];
        dp[i] %= MOD;
      }
    }
  }

  return dp[n];
}

int main() {

  string s;
  cin >> s;

  int k;
  cin >> k;

  cout << numWays(s, k) << endl;
}