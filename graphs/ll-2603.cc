#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> adj;
  const int large = 5 * 1e4;
  typedef long long ll;

  int dfs(int u, int parent, int dist, vector<int> &coins) {
    int max_distance = coins[u] ? dist : -1;
    for (auto node : adj[u]) {
      if (node != parent) {
        int d = dfs(node, u, dist + 1, coins);
        if (d != -1) {
          max_distance = max(max_distance, d);
        }
      }
    }
    return max_distance;
  }

public:
  int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
    int n = coins.size();
    adj.resize(n);
    vector<vector<ll>> grid(n, vector<ll>(n, large));

    for (auto edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
      grid[u][v] = 1;
      grid[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
      grid[i][i] = 0;
    }

    for (int via = 0; via < n; via++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
        }
      }
    }
    int minimax_distance = INT_MAX;
    int optimal_node = -1;

    for (int i = 0; i < n; i++) {
      ll max_distance_to_coin = 0;
      for (int j = 0; j < n; j++) {
        if (coins[j]) {
          max_distance_to_coin = max(max_distance_to_coin, grid[i][j]);
        }
      }
      if (max_distance_to_coin < minimax_distance) {
        minimax_distance = max_distance_to_coin;
        optimal_node = i;
      }
    }

    int parent = optimal_node;

    int steps = 0;

    for (auto node : adj[parent]) {
      int dist = dfs(node, parent, 1, coins);
      if (dist == -1)
        continue;

      dist = dist > 2 ? dist - 2 : 0;
      steps += (dist * 2);
    }

    return steps;
  }
};

int main() {
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
  vector<int> coins = {1, 0, 0, 0, 0, 1};

  Solution s;
  s.collectTheCoins(coins, edges);

  return 0;
}
