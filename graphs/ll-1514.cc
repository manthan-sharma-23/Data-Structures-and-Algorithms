#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start_node,
                        int end_node) {

    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      double wt = succProb[i];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    priority_queue<pair<double, int>> pq;
    vector<double> dist(n, 0.0);

    pq.push({1.0, start_node});
    dist[start_node] = 1.0;

    while (!pq.empty()) {
      auto [curr_prob, u] = pq.top();
      pq.pop();

      if (u == end_node) {
        return curr_prob;
      }

      for (auto &[v, wt] : adj[u]) {
        double new_prob = curr_prob * wt;
        if (new_prob > dist[v]) {
          dist[v] = new_prob;
          pq.push({new_prob, v});
        }
      }
    }

    return 0.0;
  }
};
