#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<vector<int>> &matrix, vector<bool> &visited, int u) {
    visited[u] = 1;

    for (auto &num : matrix[u]) {
      if (!visited[num]) {
        dfs(matrix, visited, num);
      }
    }
  }

  int numProvinces(vector<vector<int>> adj, int V) {
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (i == j)
          continue;

        if (adj[i][j] == 1) {
          matrix[i].push_back(j);
        }
      }
    }
    int count{0};

    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        count++;
        dfs(matrix, visited, i);
      }
    }

    return count;
  }
};