#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  bool bfs_(int node, vector<int> vis, vector<int> adj[]) {
    vis[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, -1});

    while (!q.empty()) {
      int pt = q.front().first;
      int parent = q.front().second;
      q.pop();

      for (auto it : adj[pt]) {
        if (!vis[it]) {
          vis[it] = 1;
          q.push({it, pt});
        } else if (parent != it) {
          return true;
        }
      }
    }
    return false;
  }

public:
  bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (bfs_(i, vis, adj)) {
          return true;
        }
      }
    }
    return false;
  }
};

class Solution_DFS {
private:
  bool isCycleDFS(vector<int> adj[], vector<bool> &visited, int node,
                  int parent) {

    visited[node] = true;

    for (auto it : adj[node]) {
      if (it == parent)
        continue;

      if (visited[it]) {
        return true;
      }

      if (isCycleDFS(adj, visited, it, node)) {
        return true;
      };
    }

    return false;
  }

public:
  bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
      if (!visited[i] && isCycleDFS(adj, visited, i, -1)) {
        return true;
      }
    }

    return false;
  }
}
