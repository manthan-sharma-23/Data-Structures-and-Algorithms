#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Kahns_algo_topo_sort_DAG {

public:
  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> topo;
    vector<int> indegree(V, 0);
    queue<int> Q;

    for (int i = 0; i < V; i++) {
      for (auto it : adj[V]) {
        indegree[it] += 1;
      }
    }

    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        Q.push(i);
      }
    }

    while (!Q.empty()) {
      auto el = Q.front();
      Q.pop();
      topo.push_back(el);

      for (auto it : adj[el]) {
        indegree[it] -= 1;
        if (indegree[it] == 0) {
          Q.push(it);
        }
      }
    }

    return topo;
  }
}
