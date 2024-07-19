#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  // Function to detect cycle in a directed graph.
  bool isCyclic(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    queue<int> q;

    for (int i = 0; i < V; i++) {
      for (auto it : adj[i]) {
        indegree[it]++;
      }
    }

    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    int count = 0;

    while (!q.empty()) {
      int node = q.front();

      q.pop();

      count++;

      for (int u : adj[node]) {
        indegree[u]--;
        if (indegree[u] == 0) {
          q.push(u);
        }
      }
    }

    return count != V;
  }
};
