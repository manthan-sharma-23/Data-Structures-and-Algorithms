#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {
    vector<vector<int>> adj(n + 1);

    for (auto edge : edges) {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    typedef pair<int, int> Node;
    queue<Node> q;

    vector<int> distance(n + 1, INT_MAX);
    vector<int> secondDistance(n + 1, INT_MAX);

    q.push({0, 1});
    distance[1] = 0;

    while (!q.empty()) {
      auto [currTime, currNode] = q.front();
      q.pop();

      for (auto neighbor : adj[currNode]) {
        int wait = 0;
        if ((currTime / change) % 2 == 1) {
          wait = change - (currTime % change);
        }
        int nextTime = currTime + wait + time;

        if (nextTime < distance[neighbor]) {
          secondDistance[neighbor] = distance[neighbor];
          distance[neighbor] = nextTime;
          q.push({nextTime, neighbor});
        } else if (nextTime > distance[neighbor] &&
                   nextTime < secondDistance[neighbor]) {
          secondDistance[neighbor] = nextTime;
          q.push({nextTime, neighbor});
        }
      }
    }

    return secondDistance[n] == INT_MAX ? -1 : secondDistance[n];
  }
};
