#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> &ls, vector<int> adj[], int vis[]) {
  vis[node] = 1;
  ls.push_back(node);

  for (auto it : adj[node]) {
    if (!vis[it]) {
      dfs(it, ls, adj, vis);
    }
  }
}

vector<int> dfsonG(int V, vector<int> adj[]) {
  int vis[V];

  for (auto i : vis) {
    i = 0;
  }
  int start = 0;
  vector<int> ls;

  dfs(0, ls, adj, vis);

  return ls;
}
