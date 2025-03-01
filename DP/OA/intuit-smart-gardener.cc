/*

link -> https://www.desiqna.in/16217/intuit-oa-coding-questions-set-29-2024

sprinklers = [1 ,1 ,2 ,1 ,0 ]
cost = [1, 3, 6, 2, 0]

minimumCost = 1 + 2 = 3 (0th and 3rd sprinkler)
*/
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int minimumCost(vector<int> &sprinklers, vector<int> &cost) {
  int n = sprinklers.size();

  vector<int> dp(n + 1, INT_MAX);

  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int cut = i - 1; cut >= 0; cut--) {
      if (sprinklers[cut - 1] + cut >= i) {
        int left = (cut - 1) - sprinklers[cut - 1];
        if (left < 0)
          left = 0;

        dp[i] = min(dp[i], dp[left] + cost[cut - 1]);
      }
    }
  }

  return dp[n];
}

int main() {

  vector<int> sprinklers = {1, 1, 2, 1, 0};
  vector<int> cost = {1, 3, 6, 2, 0};

  cout << minimumCost(sprinklers, cost) << endl;
}