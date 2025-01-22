#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<int> adj[], int u, vector<bool> &visited) {
    visited[u] = true;

    for (auto node : adj[u]) {
      if (!visited[node])
        dfs(adj, node, visited);
    }
  }

  bool isConnected(int V, vector<int> adj[]) {
    int nonZeroDegreeVertex = -1;

    for (int i = 0; i < V; i++) {
      if (adj[i].size() != 0) {
        nonZeroDegreeVertex = i;
        break;
      }
    }

    vector<bool> visited(V, 0);
    dfs(adj, nonZeroDegreeVertex, visited);

    for (int i = 0; i < V; i++) {
      if (visited[i] != true && adj[i].size() > 0)
        return false;
    }

    return true;
  }

  int isEulerCircuit(int V, vector<int> adj[]) {

    if (!isConnected(V, adj)) {
      return false;
    }

    int oddDegreeCount = 0;

    for (int i = 0; i < V; i++) {
      if (adj[i].size() % 2 != 0) {
        oddDegreeCount++;
      }
    }

    if (oddDegreeCount > 2) {
      return 0;
    } else if (oddDegreeCount == 2) {
      return 1;
    } else {
      return 2;
    }
  }
};