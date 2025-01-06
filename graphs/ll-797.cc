#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int N;
  void dfs(vector<vector<int>> &graph, set<vector<int>> &res, vector<int> &path,
           int u) {
    if (u == N - 1) {
      res.insert(path);
      return;
    }

    for (const auto &node : graph[u]) {
      path.push_back(node);
      dfs(graph, res, path, node);
      path.pop_back();
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int n = graph.size();
    N = n;

    set<vector<int>> res;

    vector<int> path;
    path.push_back(0);

    dfs(graph, res, path, 0);

    return vector<vector<int>>(res.begin(), res.end());
  }
};