#include <vector>

using namespace std;

class Solution {
public:
  const double limit = -1e5;
  vector<vector<int>> adj;
  int target, time;

  double result = 1.0;

  double dfs(int u, int parent, bool isRoot = false, int level = 0) {
    double poolsize = adj[u].size() + (isRoot ? 0 : -1);

    if (u == target) {
      if (level == time)
        return 1.0;
      else if (level < time) {
        return poolsize == 0 ? 1.0 : 0.0;
      } else {
        return 0.0;
      }
    }

    double probab = 0.0;

    for (auto node : adj[u]) {
      if (node == parent)
        continue;

      probab = max(probab,
                   (double)(1.0 / poolsize) * dfs(node, u, false, level + 1));
    }

    return probab;
  }

  double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
    adj.resize(n + 1);
    this->target = target;
    this->time = t;

    for (auto &edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    return dfs(1, -1, true);
  }
};