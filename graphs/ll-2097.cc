#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
    int n = pairs.size();

    unordered_map<int, int> endsWith;

    for (int i = 0; i < n; i++) {
      endsWith[pairs[i][1]] = i;
    }

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    queue<int> q;

    for (int i = 0; i < n; i++) {
      auto pair = pairs[i];
      int u = pair[0];

      if (endsWith.find(u) != endsWith.end()) {
        indegree[i]++;
        adj[endsWith[u]].push_back(i);
      }
    }

    int val = 0;
    while (q.empty()) {
      for (int i = 0; i < n; i++) {
        if (indegree[i] == val) {
          q.push(i);
        }

        if (q.size() == 1)
          break;
      }

      val++;
    }
    vector<int> occurence(n, 0);
    vector<vector<int>> path;

    while (!q.empty()) {
      int currIdx = q.front();
      q.pop();
      if (occurence[currIdx] == 0) {
        occurence[currIdx] = 1;
        path.push_back(pairs[currIdx]);
      }

      for (auto nextIdx : adj[currIdx]) {
        indegree[nextIdx]--;
        if (indegree[nextIdx] == 0) {
          q.push(nextIdx);
        }
      }
    }

    return path;
  }
};