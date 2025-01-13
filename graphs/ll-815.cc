#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {

    unordered_map<int, vector<int>> adj;

    for (auto &route : routes) {
      route.push_back(route[0]);
      for (int i = 0; i < route.size() - 1; i++) {
        adj[route[i]].push_back(route[i + 1]);
      }
    }

    queue<int> q;
    int level = 0;
    vector<bool> visited(adj.size() + 1, false);
    q.push(source);

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        auto u = q.front();
        q.pop();

        visited[u] = true;

        if (u == target) {
          return level;
        }

        for (const int node : adj[u]) {
          if (!visited[node]) {
            q.push(node);
          }
        }
      }
      level++;
    }

    return -1;
  }
};