#include <cstring>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int shortestPathLength(vector<vector<int>> &graph) {

    int n = graph.size();

    if (n == 0)
      return 0;

    typedef pair<int, int> Node;

    const int allVisitedState = (1 << n) - 1;

    vector<vector<bool>> visited(n, vector<bool>(allVisitedState, false));
    queue<Node> q;

    for (int i = 0; i < n; i++) {
      int state = (1 << i);

      q.push({i, state});
      visited[i][state] = true;
    }

    int level = 0;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        auto [currNode, currState] = q.front();
        q.pop();

        for (const int &nextNode : graph[currNode]) {
          int nextState = currState | (1 << nextNode);

          if (nextState == allVisitedState) {
            return level + 1;
          }

          if (!visited[nextNode][nextState]) {
            visited[nextNode][nextState] = 1;
            q.push({nextNode, nextState});
          }
        }
      }

      level++;
    }

    return -1;
  }
};