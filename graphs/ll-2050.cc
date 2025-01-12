#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
    int N = n + 1;
    vector<vector<int>> adj(N);
    vector<int> inDegree(N, 0);
    typedef pair<int, int> P;
    inDegree[0] = -1;

    for (auto &relation : relations) {
      int a = relation[0];
      int b = relation[1];

      adj[a].push_back(b);
      inDegree[b]++;
    }

    vector<int> maxTime(N, -1);

    queue<int> q;

    for (int i = 1; i < N; i++) {
      if (inDegree[i] == 0) {
        maxTime[i] = time[i - 1];
        q.push(i);
      }
    }

    while (!q.empty()) {

      int currSub = q.front();
      q.pop();

      for (int nextSub : adj[currSub]) {
        maxTime[nextSub] =
            max(maxTime[nextSub], maxTime[currSub] + time[nextSub - 1]);
        inDegree[nextSub]--;

        if (inDegree[nextSub] == 0) {
          q.push(nextSub);
        }
      }
    }
    int max_Time = 0;

    for (auto time : maxTime) {
      if (time != -1)
        max_Time = max(time, max_Time);
    }

    return max_Time;
  }
};