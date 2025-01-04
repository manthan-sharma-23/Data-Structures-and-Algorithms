#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string findOrder(vector<string> &dict, int k) {
    vector<vector<int>> adj(k);
    vector<int> indegree(k, 0);
    for (int i = 0; i < dict.size() - 1; i++) {
      string s = dict[i];
      string s1 = dict[i + 1];
      int len = min(s.length(), s1.length());

      for (int j = 0; j < len; j++) {
        if (s[j] != s1[j]) {
          adj[s[j] - 'a'].push_back(s1[j] - 'a');
          indegree[s1[j] - 'a']++;
          break;
        }
      }
    }

    queue<int> q;
    for (int i = 0; i < k; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    vector<int> topo;
    while (!q.empty()) {
      int front = q.front();
      q.pop();
      topo.push_back(front);

      for (auto &num : adj[front]) {
        indegree[num]--;
        if (indegree[num] == 0) {
          q.push(num);
        }
      }
    }

    if (topo.size() != k) {
      return "";
    }

    string order = "";
    for (auto &i : topo) {
      order.push_back(char(i + 'a'));
    }

    return order;
  }
};
