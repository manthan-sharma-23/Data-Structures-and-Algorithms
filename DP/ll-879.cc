#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  const int MOD = 1e9 + 7;
  int dp[101][101][101];

  int f(int idx, int people, int profit, const vector<pair<int, int>> &crimes) {
    if (people < 0)
      return 0;
    if (idx == crimes.size())
      return (profit <= 0) ? 1 : 0;

    if (dp[idx][people][profit] != -1)
      return dp[idx][people][profit];

    int ways = f(idx + 1, people, profit, crimes) % MOD;
    if (crimes[idx].first <= people) {
      ways = (ways + f(idx + 1, people - crimes[idx].first,
                       max(0, profit - crimes[idx].second), crimes)) %
             MOD;
    }

    return dp[idx][people][profit] = ways;
  }

  int profitableSchemes(int n, int minProfit, vector<int> &group,
                        vector<int> &profit) {
    memset(dp, -1, sizeof(dp));
    vector<pair<int, int>> Crimes;
    for (size_t i = 0; i < group.size(); i++) {
      Crimes.emplace_back(group[i], profit[i]);
    }

    return f(0, n, minProfit, Crimes);
  }
};
