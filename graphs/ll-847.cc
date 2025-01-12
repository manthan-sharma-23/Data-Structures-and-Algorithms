#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int shortestPathLength(vector<vector<int>> &graph) {
    typedef pair<int, int> Node;
    int n = graph.size();
    int final_mask = (1 << n) - 1;

    queue<Node> q;
    vector<vector<bool>> visited(n, vector<bool>(final_mask, false));

    for (int i = 0; i < n; i++) {
      int mask = 1 << i;
      
    }
  }
};