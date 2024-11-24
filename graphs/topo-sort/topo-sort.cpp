#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
  visited[node] = 1;

  for (auto it : adj[node]) {
    if (!visited[it]) {
      dfs(it, adj, visited, st);
    }
  }
  st.push(node);
}

vector<int> topo_sort(vector<int> adj[], int V) {
  stack<int> st;
  vector<bool> visited(V, 0);
  vector<int> topo;

  // Perform DFS for all unvisited nodes
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      dfs(i, adj, visited, st);
    }
  }

  // Extract nodes from the stack to form the topological sort
  while (!st.empty()) {
    topo.push_back(st.top());
    st.pop();
  }

  return topo;
}

int main() {
  vector<int> adj[10];
  adj[0] = {1};
  adj[1] = {2, 5};
  adj[2] = {3, 4};
  adj[3] = {4};
  adj[4] = {6, 9};
  adj[5] = {6, 7};
  adj[6] = {};
  adj[7] = {6, 8};
  adj[8] = {};
  adj[9] = {};

  auto topo = topo_sort(adj, 10);

  for (auto it : topo) {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}
