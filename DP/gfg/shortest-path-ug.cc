#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> shortestPath(vector<vector<int>> &adj, int src) {

    int n = adj.size();
    queue<int> q;

    vector<int> dist(n, INT_MAX);

    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {

      auto top = q.front();
      q.pop();

      for (auto &num : adj[top]) {
        if (dist[num] > dist[top] + 1) {
          dist[num] = dist[top] + 1;
          q.push(num);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (dist[i] == INT_MAX)
        dist[i] = -1;
    }

    return dist;
  }
};