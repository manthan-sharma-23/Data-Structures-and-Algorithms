#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  typedef pair<int, int> Node;
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);

    for (const auto &edge : times) {
      int u = edge[0], v = edge[1], w = edge[2];
      adj[u].push_back({v, w});
    }

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<int> timeTaken(n + 1, INT_MAX);

    pq.push({0, k});
    timeTaken[k] = 0;

    while (!pq.empty()) {
      auto [currTime, currNode] = pq.top();
      pq.pop();

      if (currTime > timeTaken[currNode])
        continue;

      for (auto &[nextNode, travelTime] : adj[currNode]) {
        int newTimeTaken = currTime + travelTime;

        if (newTimeTaken < timeTaken[nextNode]) {
          timeTaken[nextNode] = newTimeTaken;
          pq.push({newTimeTaken, nextNode});
        }
      }
    }

    int maxTime = 0;

    for (int i = 1; i <= n; i++) {
      if (timeTaken[i] == INT_MAX)
        return -1;
      maxTime = max(maxTime, timeTaken[i]);
    }

    return maxTime;
  }
};
