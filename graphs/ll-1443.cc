#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int N;

  int dfs(int src, int parent, vector<vector<int>> &adj,
          vector<bool> &hasApple) {
    int totalTime = 0;

    for (int &child : adj[src]) {
      if (child == parent)
        continue;

      int timeTaken = dfs(child, src, adj, hasApple);

      if (timeTaken > 0 || hasApple[child]) {
        totalTime += timeTaken + 2;
      }
    }

    return totalTime;
  }

  int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
    vector<vector<int>> adj(n);
    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    return dfs(0, -1, adj, hasApple);
  }
};