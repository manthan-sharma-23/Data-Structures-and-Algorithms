// link  ->
// https://www.desiqna.in/17560/google-oa-prime-string-july-2024-kumar-k

#include <charconv>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int limit = 1e6;
const int MOD = 1e9 + 7;
vector<bool> isPrime(limit, false);

void sieve(int n) {
  isPrime.assign(n + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

bool isStringPrime(string a) {
  int number;
  from_chars(a.data(), a.data() + a.size(), number);

  if (number < 2 || number > limit)
    return false;
  return isPrime[number];
}

int numWaysToSplitStringInPrime(string &s) {
  sieve(limit);

  int n = s.length();

  vector<long long> dp(n + 1, 0);

  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int c = i - 1; c >= 0 && i - c <= 6; c--) {
      if (isStringPrime(s.substr(c + 1, i - c))) {
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

  cout << numWaysToSplitStringInPrime(s) << endl;
}