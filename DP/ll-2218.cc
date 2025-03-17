#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxValueOfCoins(vector<vector<int>> &piles, int k) {
    int n = piles.size();

    vector<vector<int>> Piles(n);

    for (int i = 0; i < n; i++) {
      auto pile = piles[i];

      vector<int> prefixPile(pile.size());

      prefixPile[0] = pile[0];
      for (int i = 1; i < pile.size(); i++) {
        prefixPile[i] = prefixPile[i - 1] + pile[i];
      }

      Piles[i] = prefixPile;
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        auto pile = Piles[i - 1];

        for (int c = 0; c <= min((int)pile.size(), j); c++) {
          int currPileSum = c > 0 ? pile[c - 1] : 0;
          dp[i][j] = max(dp[i][j], currPileSum + dp[i - 1][j - c]);
        }
      }
    }

    return dp[n][k];
  }
};