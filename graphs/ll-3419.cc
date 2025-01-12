#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minMaxWeight(int n, vector<vector<int>> &edges, int threshold) {

    vector<bool> visited(n, false);
    vector<vector<pair<int, int>>> adj(n);

    for (const vector<int> &edge : edges) {
      int from = edge[1];
      int to = edge[0];
      int wt = edge[2];

      adj[from].push_back({to, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, 0});

    int max_wt = -1;
    int visit = 0;

    while (!pq.empty()) {
      auto [dist, parent] = pq.top();
      pq.pop();

      if (visited[parent])
        continue;

      visited[parent] = true;

      max_wt = max(max_wt, dist);
      visit++;

      for (const auto &[node, wt] : adj[parent]) {
        if (!visited[node]) {
          pq.push({wt, node});
        }
      }
    }

    if (visit < n)
      return -1;

    return max_wt;
  }
};

class Good_soln {
  int dfs(int i, int m, vector<vector<pair<int, int>>> &ral, vector<int> &vis) {
    int res = vis[i] = 1;
    for (auto [j, w] : ral[i])
      if (w <= m && !vis[j])
        res += dfs(j, m, ral, vis);
    return res;
  }

public:
  int minMaxWeight(int n, vector<vector<int>> &edges, int threshold) {
    vector<vector<pair<int, int>>> ral(n);
    for (auto &e : edges)
      ral[e[1]].push_back({e[0], e[2]});
    int l = 1, r = 1000001;
    while (l < r) {
      int m = (l + r) / 2;
      if (vector<int> vis(n); dfs(0, m, ral, vis) == n)
        r = m;
      else
        l = m + 1;
    }
    return l == 1000001 ? -1 : l;
  }
};