#include <vector>

using namespace std;

vector<int> weights;
vector<vector<int>> adj;
vector<vector<int>> dp;
vector<vector<int>> iSum;
vector<int> iMax;

const int take = 1, notTake = 0, notTakeChildToo = 0;

void solve(int node, int parent) {

  for (auto child : adj[node]) {
    if (child == parent)
      continue;

    solve(child, node);
  }

  // take this node

  dp[node][take] = weights[node];
}

int maxSumAtLeastDist3(int V, vector<vector<int>> edges, vector<int> &W) {
  adj.resize(V);
  dp.resize(V, vector<int>(3, 0));
  iSum.resize(V, vector<int>(3, 0));
  iMax.resize(V);
  weights = W;

  for (auto &edge : edges) {
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}
