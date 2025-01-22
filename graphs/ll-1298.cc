#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int maxCandies(vector<int> &status, vector<int> &candies,
                 vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                 vector<int> &initialBoxes) {
    int n = status.size();
    const int key_edge = 1, box_edge = 2;

    vector<vector<pair<int, int>>> adj(n);
    vector<pair<bool, bool>> Boxes(n, {false, false});
    vector<bool> visited(n, false);
    queue<int> q;

    for (int i = 0; i < n; i++) {
      for (int key : keys[i]) {
        adj[i].push_back({key, key_edge});
      }
      for (int box : containedBoxes[i]) {
        adj[i].push_back({box, box_edge});
      }
    }

    for (int i = 0; i < n; i++) {
      if (status[i]) {
        Boxes[i].first = true;
      }
    }

    for (int box : initialBoxes) {
      Boxes[box].second = true;
      if (status[box]) {
        q.push(box);
        visited[box] = true;
      }
    }

    int ans = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      ans += candies[u];

      for (auto [box_node, edge_type] : adj[u]) {
        if (edge_type == key_edge) {
          Boxes[box_node].first = true;
        } else {
          Boxes[box_node].second = true;
        }

        if (Boxes[box_node].first && Boxes[box_node].second &&
            !visited[box_node]) {
          q.push(box_node);
          visited[box_node] = true;
        }
      }
    }

    return ans;
  }
};
