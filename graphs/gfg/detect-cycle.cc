#include <queue>
#include <vector>

using namespace std;

class DFS_Solution {
public:
  bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int u, int parent) {
    visited[u] = true;

    for (auto &nums : adj[u]) {
      if (nums == parent)
        continue;
      if (visited[nums] == true)
        return true;

      if (dfs(adj, visited, nums, u))
        return true;
    }

    return false;
  }
  bool isCycle(vector<vector<int>> &adj) {
    int V = adj.size();
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
      if (!visited[i] && dfs(adj, visited, i, -1)) {
        return true;
      }
    }

    return false;
  }
};

class BFS_Solution {
public:
  bool isCycle(vector<vector<int>> &adj) {
    int V = adj.size();
    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++) {
      if (visited[i])
        continue;

      queue<pair<int, int>> q;
      q.push({i, -1});
      visited[i] = true;
      while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto &j : adj[node]) {
          if (j == parent)
            continue;

          if (visited[j] == true)
            return true;

          visited[j] = true;
          q.push({j, node});
        }
      }
    }
    return false;
  }
};