#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {

    vector<int> inDegree(n, 0);

    for (const auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];

      inDegree[v]++;
    }

    vector<int> res;

    for (int i = 0; i < n; i++) {
      if (inDegree[i] == 0)
        res.push_back(i);
    }

    return res;
  }
};