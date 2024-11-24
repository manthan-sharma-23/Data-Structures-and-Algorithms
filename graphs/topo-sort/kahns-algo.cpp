#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

vector<int> kahns_topo_sort(int V, vector<int> adj[]) {
  vector<int> topo;
  vector<int> indegree(V, 0);

  for (int i = 0; i < V; i++) {
    for (auto it : adj[i]) {
      indegree[it]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    auto node = q.front();
    q.pop();

    topo.push_back(node);

    for (auto it : adj[node]) {
      indegree[it]--;
      if (indegree[it] == 0) {
        q.push(it);
      }
    }

    return topo;
  }
