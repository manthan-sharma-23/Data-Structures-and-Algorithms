#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<vector<int>> adj, vector<bool> &visited, int node) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;

    for (int neighbour : adj[node]) {
      if (!visited[neighbour]) {
        dfs(adj, visited, neighbour);
      }
    }
  }

  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && i != j) {
          adj[i].push_back(j);
        }
      }
    }

    vector<bool> visited(n, false);
    int circles = 0;

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        circles++;
        dfs(adj, visited, i);
      }
    }

    return circles;
  }
};

class BFS_Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();

    vector<bool> visited(n, 0);
    int circles{0};

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        visited[i] = true;
        circles++;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
          int node = q.front();
          q.pop();

          for (int j = 0; j < n; j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
              q.push(j);
              visited[j] = true;
            }
          }
        }
      }
    }

    return circles;
  }
};