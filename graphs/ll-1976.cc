#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  typedef pair<int, int> Node;
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<Node>> adj;
    const int MOD = 1e9 + 7;

    for (auto &road : roads) {
      adj[road[0]].emplace_back(road[1], road[2]);
      adj[road[1]].emplace_back(road[0], road[2]);
    }

    vector<int> distance(n, INT_MAX), ways(n, 0);

    ways[0] = 1;
    distance[0] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
      auto top = pq.top();
      int current_node = top.second;
      int current_distance = top.first;
      pq.pop();

      for (auto &node : adj[current_node]) {
        int new_dist = current_distance + node.second;
        int new_node = node.first;

        if (new_dist < distance[new_node]) {
          distance[new_node] = new_dist;
          ways[new_node] = (ways[current_node]) % MOD;
          pq.emplace(new_dist, new_node);
        } else if (new_dist == distance[new_node]) {
          ways[new_node] = (ways[new_node] + ways[current_node]) % MOD;
        }
      }
    }

    return ways[n - 1] % MOD;
  }
};