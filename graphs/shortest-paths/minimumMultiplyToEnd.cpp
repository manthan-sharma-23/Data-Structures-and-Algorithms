#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumMultiplications(vector<int> &arr, int start, int end) {

    if (start == end) {
      return 0;
    }

    int mod = 100000;
    queue<pair<int, int>> q;
    vector<int> dist(mod, INT_MAX);

    dist[start] = 0;
    q.push({start, 0});

    while (!q.empty()) {
      int node = q.front().first;
      int steps = q.front().second;

      q.pop();

      for (auto it : arr) {
        int num = (it * node) % mod;
        if (steps + 1 < dist[num]) {
          dist[num] = steps + 1;
          if (num == end) {
            return steps + 1;
          }
          q.push({num, steps + 1});
        }
      }
    }

    return -1;
  }
};
