#include <map>
#include <string>
#include <vector>

using namespace std;

int numWays(string &s, vector<int> &A) {
  int n = s.length();

  vector<int> dp(n + 1, 0);

  map<int, int> mp;

  dp[0] = 1;

  for (auto i = 0; i < 26; i++) {
    if (A[i] > 0)
      mp[i] = A[i];
  }

  for (int i = 1; i <= n; i++) {
    auto temp = mp;

    

    for (int cut = i - 1; cut >= 0; cut--) {
    }
  }
  return dp[n];
}
