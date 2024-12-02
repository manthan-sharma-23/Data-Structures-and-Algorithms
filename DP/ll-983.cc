#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class BFSolution {
public:
  int findNextIndex(vector<int> days, int currentIndex, int duration) {
    int limit = days[currentIndex] + duration - 1;
    return upper_bound(days.begin() + currentIndex, days.end(), limit) -
           days.begin();
  };

  int dfs(vector<int> days, vector<int> costs, int idx, vector<int> &memo) {
    if (idx == days.size()) {
      return 0;
    }

    if (memo[idx] != -1)
      return memo[idx];

    int one_day = costs[0] + dfs(days, costs, idx + 1, memo);

    int seven_day =
        costs[1] + dfs(days, costs, findNextIndex(days, idx, 7), memo);

    int thirty_day =
        costs[2] + dfs(days, costs, findNextIndex(days, idx, 30), memo);

    return memo[idx] = min({one_day, seven_day, thirty_day});
  }

  int mincostTickets(vector<int> &days, vector<int> &costs) {
    vector<int> memo(days.size(), -1);
    return dfs(days, costs, 0, memo);
  }
};

class DPSolution {

public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    vector<int> dp(days.size() + 1, 1e5);
    dp[0] = min({costs[0], costs[1], costs[2]});

    for (int i = 1; i < days.size(); i++) {
      int last7 = i, last30 = i;

      while (last7 >= 0 && days[last7] + 7 > days[i]) {
        last7--;
      }
      while (last30 >= 0 && days[last30] + 30 > days[i]) {
        last30--;
      }

      dp[i] = min(dp[i], dp[i - 1] + costs[0]);
      if (last7 == -1)
        dp[i] = min(dp[i], costs[1]);
      else
        dp[i] = min(dp[i], dp[last7] + costs[1]);

      if (last30 == -1)
        dp[i] = min(dp[i], costs[2]);
      else
        dp[i] = min(dp[i], dp[last30] + costs[2]);
    }

    return dp[days.size()];
  }
};

class MoreOptimizedSolution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    queue<pair<int, int>> last7, last30;
    int cost{0};
    for (auto d : days) {
      while (!last7.empty() && last7.front().first + 7 <= d)
        last7.pop();
      while (!last30.empty() && last30.front().first + 30 <= d)
        last30.pop();

      last7.push({d, cost + costs[1]});
      last30.push({d, cost + costs[2]});

      cost =
          min({cost + costs[0], last7.front().second, last30.front().second});
    }

    return cost;
  }
};

int main() {
  vector<int> days = {1, 4, 6, 7, 8, 20};
  vector<int> costs = {2, 7, 15};

  MoreOptimizedSolution s;
  auto cost = s.mincostTickets(days, costs);

  cout << cost << endl;

  return 0;
}
