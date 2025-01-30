#include <algorithm>
#include <climits>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  vector<ll> coins;
  vector<vector<int>> adj;
  vector<int> costs;

  vector<ll> dfs(int u, int parent) {
    vector<ll> subTreeCoins = {costs[u]};

    for (auto node : adj[u]) {
      if (node == parent)
        continue;

      auto V = dfs(node, u);

      for (auto t : V) {
        subTreeCoins.push_back(t);
      }
    }

    sort(subTreeCoins.begin(), subTreeCoins.end(), greater<ll>());

    int sz = subTreeCoins.size();

    if (sz < 3) {
      coins[u] = 1;
      return subTreeCoins;
    }
    bool larger = subTreeCoins[1] * subTreeCoins[2] >
                  subTreeCoins[sz - 1] * subTreeCoins[sz - 2];
    if (larger) {
      coins[u] = subTreeCoins[0] * subTreeCoins[1] * subTreeCoins[2];
    } else if (!larger) {
      coins[u] = subTreeCoins[0] * subTreeCoins[sz - 1] * subTreeCoins[sz - 2];
    }

    if (subTreeCoins[u] < 0) {
      subTreeCoins[u] = 0;
    }

    if (sz <= 5)
      return subTreeCoins;

    return {subTreeCoins[0], subTreeCoins[1], subTreeCoins[2],
            subTreeCoins[sz - 1], subTreeCoins[sz - 2]};
  }

  vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &cost) {
    int n = cost.size();
    adj.resize(n);
    costs = cost;

    for (auto &edge : edges) {
      int u = edge[0], v = edge[1];

      adj[u].push_back(v), adj[v].push_back(u);
    }

    dfs(0, -1);

    return coins;
  }
};