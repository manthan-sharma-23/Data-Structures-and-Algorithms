#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int k;
  typedef long long ll;
  typedef pair<ll, ll> Node;
  vector<vector<Node>> adj;

  ll memo[100010][2];
  ll dfs(int u, int parent, bool isParentRemoved) {
    if (memo[u][isParentRemoved] != -1) {
      return memo[u][isParentRemoved];
    }

    int edgesToRemove = max(0, (int)adj[u].size() - k - isParentRemoved);
    vector<Node> pairs;
    ll answer = 0;

    for (auto &[node, wt] : adj[u]) {
      if (node == parent)
        continue;

      ll remove = dfs(node, u, 1);
      ll dontRemove = wt + dfs(node, u, 0);
      pairs.emplace_back(dontRemove, remove);
    }

    sort(pairs.begin(), pairs.end(), [](const Node &a, const Node &b) {
      return (a.first - a.second) < (b.first - b.second);
    });

    for (int i = 0; i < pairs.size(); i++) {
      auto &[dontRemove, remove] = pairs[i];

      if (i < edgesToRemove) {
        answer += remove;
      } else {
        answer += max(remove, dontRemove);
      }
    }

    return memo[u][isParentRemoved] = answer;
  }

  long long maximizeSumOfWeights(vector<vector<int>> &edges, int k) {
    this->k = k;
    int n = edges.size() + 1;
    adj.assign(n, vector<Node>());

    memset(memo, -1, sizeof(memo));

    for (const auto &edge : edges) {
      int u = edge[0], v = edge[1], wt = edge[2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    return dfs(0, -1, 0);
  }
};
