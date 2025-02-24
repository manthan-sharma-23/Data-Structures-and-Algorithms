#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  const int largest5 = 15625;
  long long binaryToDecimal(string binary) { return stoi(binary, nullptr, 2); }

  bool isValid(string binr) {
    if (binr[0] == '0')
      return false;
    long long num = binaryToDecimal(binr);

    return largest5 % num == 0;
  }

  int minimumBeautifulSubstrings(string s) {
    int n = s.length();
    int maxPartitions = n;
    const int LARGE = 1e7;

    vector<int> dp(n + 1, LARGE);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int cuts = i - 1; cuts >= 0; cuts--) {
        string subs = s.substr(cuts, i + cuts + 1);
        if (!isValid(subs))
          continue;
        dp[i] = min(dp[i], 1 + dp[cuts]);
      }
    }

    return dp[n] == LARGE ? -1 : dp[n];
  }
};