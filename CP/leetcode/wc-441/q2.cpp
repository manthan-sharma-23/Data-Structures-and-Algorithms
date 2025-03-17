#include <algorithm>
#include <climits>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
    int n = nums.size();
    unordered_map<int, set<int>> mp;

    for (int i = 0; i < n; i++) {
      mp[nums[i]].insert(i);
    }

    vector<int> res(queries.size());

    for (int i = 0; i < queries.size(); i++) {
      int query = queries[i];
      int num = nums[query];
      auto &indices = mp[num];

      if (indices.size() <= 1) {
        res[i] = -1;
        continue;
      }

      auto it = indices.lower_bound(query);

      int rightDist = INT_MAX, leftDist = INT_MAX;

      if (next(it) != indices.end()) {
        rightDist = (*next(it) - *it + n) % n;
      } else {
        rightDist = (*indices.begin() - *it + n) % n;
      }

      if (it != indices.begin()) {
        leftDist = (*it - *prev(it) + n) % n;
      } else {
        leftDist = (*it - *indices.rbegin() + n) % n;
      }

      res[i] = min(leftDist, rightDist);
    }

    return res;
  }
};
