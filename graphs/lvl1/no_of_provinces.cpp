#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  void dfs(int node, int vis[], vector<vector<int>> adj) {
    vis[node] = 1;
    for (auto i : adj[node]) {
      if (!vis[i]) {
        vis[i] = 1;
        dfs(i, vis, adj);
      }
    }
  }

  vector<vector<int>> convertToAdjList(const vector<vector<int>> &matrix,
                                       int V) {

    vector<vector<int>> adj(V);
    for (int i = 1; i < V; i++) {
      for (int j = 1; j < V; j++) {
        if (matrix[i][j] == 1 && i != j) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    return adj;
  }

  void print2D(vector<vector<int>> v) {
    for (auto it : v) {
      for (auto j : it) {
        cout << j << " ";
      }
      cout << endl;
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int V = isConnected.size();
    vector<vector<int>> adjL = convertToAdjList(isConnected, V);

    print2D(adjL);

    int visited[V];
    for (auto i : visited) {
      i = 0;
    }
    int cnt = 0;

    for (int i = 0; i < V; i++) {
      if (!visited[i]) {

        cnt++;
        dfs(i, visited, adjL);
      }
    }

    return cnt;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> v = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

  int n = sol.findCircleNum(v);

  cout << n << endl;
}
