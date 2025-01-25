#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> adj;
  vector<int> count_in_paths;
  vector<int> parents;
  vector<int> levels;
  vector<vector<int>> costs;

  const int HALF_COST = 0, NOT_HALF_COST = 1;

  void dfs(int u, int parent, int level) {
    parents[u] = parent;
    levels[u] = level;

    for (auto child : adj[u]) {
      if (child == parent)
        continue;

      dfs(child, u, level + 1);
    }
  }

  void Path(int u, int v) {
    int U = u, V = v;
    if (levels[u] < levels[v]) {
      U = v, V = u;
    }

    while (levels[U] != levels[V]) {
      count_in_paths[U]++;
      U = parents[U];
    }

    while (U != V) {
      count_in_paths[U]++;
      count_in_paths[V]++;

      U = parents[U];
      V = parents[V];
    }
  }

  void minimizeCost(int src, int parent, vector<int> &prices) {

    for (auto child : adj[src]) {
      if (child != parent) {
        minimizeCost(child, src, prices);
      }
    }

    costs[src][HALF_COST] = (prices[src] * count_in_paths[src]) / 2;

    for (auto child : adj[src]) {
      if (child != parent)
        costs[src][HALF_COST] += costs[child][NOT_HALF_COST];
    }

    costs[src][NOT_HALF_COST] = (prices[src] * count_in_paths[src]);

    for (auto child : adj[src]) {
      if (child != parent)
        costs[src][NOT_HALF_COST] +=
            min(costs[child][NOT_HALF_COST], costs[child][HALF_COST]);
    }
  }

public:
  int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price,
                        vector<vector<int>> &trips) {
    adj.resize(n);
    costs.resize(n, vector<int>(2, 0));
    count_in_paths.resize(n, 0);
    parents.resize(n, -1);
    levels.resize(n, 0);

    for (auto edge : edges) {
      int u = edge[0], v = edge[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(0, -1, 0);

    for (const auto &trip : trips)
      Path(trip[0], trip[1]);

    minimizeCost(0, -1, price);

    return min(costs[0][HALF_COST], costs[0][NOT_HALF_COST]);
  }
};