#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses);

    for (auto &pre : prerequisites) {
      int u = pre[0];
      int v = pre[1];
      adj[v].push_back(u);
    }

    vector<int> indegree(numCourses, 0);

    for (int i = 0; i < numCourses; i++) {
      for (auto &num : adj[i]) {
        indegree[num]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (!indegree[i]) {
        q.push(i);
      }
    }

    vector<int> res;
    while (!q.empty()) {
      int front = q.front();
      q.pop();
      res.push_back(front);

      for (auto &num : adj[front]) {
        indegree[num]--;
        if (!indegree[num]) {
          q.push(num);
        }
      }
    }

    if (res.size() != numCourses)
      return {};

    return res;
  }
};
