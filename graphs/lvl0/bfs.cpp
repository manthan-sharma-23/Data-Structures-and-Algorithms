#include <bits/stdc++.h>

using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
  // Code here
  int vis[V];
  for (auto it : vis) {
    it = 0;
  }

  vis[0] = 1;

  queue<int> q;
  q.push(0);

  vector<int> bfs;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (auto it : adj[node]) {
      if (!vis[it]) {
        vis[it] = 1;
        q.push(it);
      }
    }
  }
  return bfs;
}
