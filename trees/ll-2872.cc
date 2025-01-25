#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> adj;
  int K;
  vector<int> value;
  int components;

  int dfs(int u, int parent) {
    int sum = 0;
    for (auto node : adj[u]) {
      if (node == parent)
        continue;

      sum += dfs(node, u);
      sum %= K;
    }

    sum += value[u];
    sum %= K;

    if (sum == 0)
      components++;

    return sum;
  }

  int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                              vector<int> &values, int k) {
    K = k;
    this->components = 0;
    value = values;
    adj.resize(n);
    for (auto edge : edges) {
      int u = edge[0], v = edge[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(0, -1);

    return components;
  }
};