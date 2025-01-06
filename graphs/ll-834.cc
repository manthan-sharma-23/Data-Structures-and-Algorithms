#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class FloydWarshall_Solution {
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    vector<vector<int>> path(n, vector<int>(n, INT_MAX));
    vector<int> distances(n, 0);

    for (int i = 0; i < n; i++) {
      path[i][i] = 0;
    }
    for (const auto &edge : edges) {
      path[edge[0]][edge[1]] = 1;
      path[edge[1]][edge[0]] = 1;
    }

    for (int via = 0; via < n; via++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (path[i][via] != INT_MAX && path[via][j] != INT_MAX) {
            path[i][j] = min(path[i][j], path[i][via] + path[via][j]);
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (path[i][j] != INT_MAX) {
          distances[i] += path[i][j];
        }
      }
    }

    return distances;
  }
};

class Optimized_Solution {
private:
  vector<vector<int>> v;
  vector<int> counter, res;

  void dfs(int i, int p = -1) {

    for (auto u : v[i]) {
      if (u == p)
        continue;

      dfs(u, i);

      counter[i] += counter[u];
    }
  }

public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    v.resize(n);

    for (int i = 0; i < n; i++) {
      int a = edges[i][0];
      int b = edges[i][1];

      v[a].push_back(b);
      v[b].push_back(a);
    }

    res.resize(n);
    counter.resize(n);
  }
};