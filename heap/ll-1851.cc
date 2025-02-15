#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &quers) {
    typedef pair<int, int> Node;

    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> queries;

    for (int i = 0; i < quers.size(); i++) {
      queries.push_back({quers[i], i});
    }

    sort(queries.begin(), queries.end());

    vector<int> ans(queries.size(), -1);

    //  wt,right
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minHeap;

    int id = 0;
    for (int i = 0; i < queries.size(); i++) {
      auto [query, qid] = queries[i];

      while (id < intervals.size() && intervals[id][0] <= query) {
        minHeap.push(
            {intervals[id][1] - intervals[id][0] + 1, intervals[id][1]});
        id++;
      }

      while (!minHeap.empty() && minHeap.top().second < query) {
        minHeap.pop();
      }

      ans[qid] = minHeap.empty() ? -1 : minHeap.top().first;
    }

    return ans;
  }
};