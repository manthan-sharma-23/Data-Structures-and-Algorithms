#include <climits>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValid(const map<char, int> &store) {
    int prevCount = -1;

    for (auto it : store) {
      if (prevCount == -1)
        prevCount = it.second;
      else {
        if (prevCount != it.second)
          return false;
      }
    }

    return true;
  }

  int minimumSubstringsInPartition(string s) {
    int n = s.length();

    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      map<char, int> store;
      store[s[i - 1]]++;
      for (int cut = i - 1; cut >= 0; cut--) {
        if (isValid(store)) {
          dp[i] = min(dp[i], 1 + dp[cut]);
        }
        if (cut > 0)
          store[s[cut - 1]]++;
      }
    }

    return dp[n] == INT_MAX ? -1 : dp[n];
  }
};