#include <vector>
using namespace std;

class Solution {
private:
  int maxPath = 0;
  int maxTime = 0;
  int N;
  vector<vector<pair<int, int>>> adj;
  vector<int> time_values;

  void dfs(int u, vector<int> &occurence, int time, int path) {

    path += occurence[u] == 0 ? time_values[u] : 0;

    if (u == 0) {
      maxPath = max(maxPath, path);
    }

    occurence[u]++;
    for (auto [node, wt] : adj[u]) {
      if (wt + time <= maxTime) {
        dfs(node, occurence, time + wt, path);
      }
    }
    occurence[u]--;
  }

public:
  int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges,
                         int maxTime) {
    int n = values.size();
    this->maxTime = maxTime;
    this->time_values = values;
    this->N = n;
    this->adj.resize(n);

    for (auto edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int wt = edge[2];

      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    vector<int> occurence(n, 0);

    dfs(0, occurence, 0, 0);

    return maxPath;
  }
};