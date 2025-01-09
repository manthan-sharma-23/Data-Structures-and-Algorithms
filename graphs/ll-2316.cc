#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
  void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node,
           int &componentSize) {
    visited[node] = true;
    componentSize++;
    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        dfs(adj, visited, neighbor, componentSize);
      }
    }
  }

public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    // Build the adjacency list
    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    // Calculate sizes of connected components
    vector<int> componentSizes;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        int componentSize = 0;
        dfs(adj, visited, i, componentSize);
        componentSizes.push_back(componentSize);
      }
    }

    long long totalNodes = n;
    long long totalPairs = totalNodes * (totalNodes - 1LL) / 2;
    long long reachablePairs = 0;

    for (int size : componentSizes) {
      reachablePairs += size * (size - 1LL) / 2;
    }

    return totalPairs - reachablePairs;
  }
};
