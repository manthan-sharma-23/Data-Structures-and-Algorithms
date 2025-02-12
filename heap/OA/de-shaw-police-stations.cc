#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int minAcquireCost(vector<int> &stations, int n, int capacity) {

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      minHeap;

  unordered_map<int, bool> visited;

  for (int i = 0; i < n; i++) {
    visited[stations[i]] = true;
    minHeap.push({0, stations[i]});
  }

  int sum = 0;
  int count = 0;

  while (!minHeap.empty() && count < capacity + n) {
    auto [dist, node] = minHeap.top();

    if (visited[node])
      continue;

    sum += dist;
    count++;
    visited[node] = 1;

    if (!visited[node + 1])
      minHeap.push({dist + 1, node + 1});

    if (!visited[node - 1])
      minHeap.push({dist + 1, node - 1});
  }

  return sum;
}