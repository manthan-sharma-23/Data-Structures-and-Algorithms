#include <queue>
#include <vector>

using namespace std;

class BFS_Solution {
public:
  bool isCyclic(int V, vector<vector<int>> adj) { return false; }
};

class DFS_Solution {
public:
  bool dfs(vector<vector<int>> adj, int u, vector<bool> &visited,
           vector<bool> &instack) {

    visited[u] = true;
    instack[u] = true;

    for (int &v : adj[u]) {
      if (!visited[v] && dfs(adj, v, visited, instack))
        return true;
      else if (instack[v] == true)
        return true;
    }

    instack[u] = false;

    return false;
  }

  bool isCyclic(int V, vector<vector<int>> adj) {
    vector<bool> visited(V, 0);
    vector<bool> instack(V, 0);

    for (int i = 0; i < V; i++) {
      if (!visited[i] && dfs(adj, i, visited, instack))
        return true;
    }

    return false;
  }
};