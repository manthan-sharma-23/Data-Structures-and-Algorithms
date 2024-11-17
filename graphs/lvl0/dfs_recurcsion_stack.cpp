#include <iostream>
#include <set>
#include <vector>

using namespace std;

// DFS Function
void dfs(int node, vector<int> adj[], set<int> &visited, vector<int> &result) {
  if (visited.find(node) == visited.end()) { // Only visit unvisited nodes
    visited.insert(node);
    result.push_back(node);
    for (auto n : adj[node]) {
      dfs(n, adj, visited, result);
    }
  }
}

// DFS Traversal Wrapper Function
vector<int> dfs_on_graph(int V, vector<int> adj[]) {
  set<int> visited_set; // To track visited nodes
  vector<int> result;   // To store DFS traversal order

  // Start DFS from node 0 (assumes connected graph)
  dfs(0, adj, visited_set, result);

  return result;
}

int main() {
  // Number of vertices
  int V = 5;

  // Adjacency List Representation
  vector<int> adj[6];
  adj[0] = {1, 4};
  adj[1] = {3, 2};
  adj[2] = {};
  adj[3] = {5, 4};
  adj[4] = {};

  // Perform DFS
  vector<int> res = dfs_on_graph(V, adj);

  // Print DFS Traversal
  for (auto i : res) {
    cout << i << " -> ";
  }
  cout << "END" << endl;

  return 0;
}
