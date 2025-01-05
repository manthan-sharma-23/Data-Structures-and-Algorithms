
#include <queue>
#include <vector>

using namespace std;
class Prims_Solution {
public:
  typedef tuple<int, int, int> Node;

  int spanningTree(int V, vector<vector<int>> vec[]) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < V; i++) {
      for (auto &edge : vec[i]) {
        int neighbor = edge[0];
        int weight = edge[1];
        adj[i].push_back({neighbor, weight});
      }
    }

    pq.push({0, 0, -1});
    vector<bool> visited(V, false);
    vector<Node> mst;
    int mstWeight = 0;

    while (!pq.empty()) {
      auto [currWt, to, from] = pq.top();
      pq.pop();

      if (visited[to])
        continue;

      visited[to] = true;

      if (from != -1) {
        mst.push_back({currWt, to, from});
        mstWeight += currWt;
      }

      for (auto &[nextNode, wt] : adj[to]) {
        if (!visited[nextNode]) {
          pq.push({wt, nextNode, to});
        }
      }
    }

    return mstWeight;
  }
};
