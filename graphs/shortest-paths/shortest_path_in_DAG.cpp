#include <bits/stdc++.h>
#include <climits>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
  void dfs(int node, vector<int> &vis, stack<int> &st,
           vector<vector<pair<int, int>>> adj) {
    vis[node] = 1;

    for (auto it : adj[node]) {
      if (!vis[it.first]) {
        dfs(it.first, vis, st, adj);
      }
    }

    st.push(node);
  }

public:
  vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
    stack<int> st;
    vector<int> dist(N, INT_MAX);
    vector<vector<pair<int, int>>> adj(N);

    for (auto it : edges) {
      if (it[0] >= 0 && it[0] < N && it[1] >= 0 && it[1] < N)
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<int> vis(N, 0);

    for (int i = 0; i < N; i++) {
      if (!vis[i]) {
        dfs(i, vis, st, adj);
      }
    }
    dist[0] = 0;

    while (!st.empty()) {
      auto node = st.top();

      st.pop();

      for (auto it : adj[node]) {
        if (it.second + dist[node] < dist[it.first]) {
          dist[it.first] = it.second + dist[node];
        }
      }
    }

    for (int i = 0; i < N; i++) {
      if (dist[i] == INT_MAX)
        dist[i] = -1;
    }

    return dist;
  }
};
