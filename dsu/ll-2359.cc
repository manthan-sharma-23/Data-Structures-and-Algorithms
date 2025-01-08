#include <algorithm> // For min and max functions
#include <vector>

using namespace std;

class Solution {
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int n = edges.size();

    vector<int> dist1(n, -1);
    int nd = node1;
    dist1[nd] = 0;
    while (nd != -1) {
      int next_node = edges[nd];
      if (next_node == -1)
        break;

      dist1[next_node] = dist1[nd] + 1;
      nd = next_node;
    }

    vector<int> dist2(n, -1);
    nd = node2;
    dist2[nd] = 0;
    while (nd != -1) {
      int next_node = edges[nd];
      if (next_node == -1)
        break;

      dist2[next_node] = dist2[nd] + 1;
      nd = next_node;
    }

    int MIN = 1e5;
    int result = -1;
    for (int i = 0; i < n; i++) {
      if (dist1[i] == -1 || dist2[i] == -1)
        continue;
      int maxDist = max(dist1[i], dist2[i]);
      if (maxDist < MIN) {
        MIN = maxDist;
        result = i;
      }
    }

    return result;
  }
};
