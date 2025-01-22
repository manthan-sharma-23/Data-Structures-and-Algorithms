#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> children;

  void dfs(int u, vector<int> &nums, vector<bool> &seen) {
    seen[nums[u]] = true;

    for (auto node : children[u]) {
      if (!seen[nums[node]]) {
        dfs(node, nums, seen);
      }
    }
  }

public:
  vector<int> smallestMissingValueSubtree(vector<int> &parents,
                                          vector<int> &nums) {

    int n = nums.size();
    children.resize(n);
    vector<int> result(n, 1);

    for (int i = 1; i < parents.size(); i++)
      children[parents[i]].push_back(i);

    int idx = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 1) {
        idx = i;
        break;
      }
    }

    if (idx == -1)
      return result;

    int maxVal = *max_element(nums.begin(), nums.end());

    vector<bool> seen(maxVal + 2, false);
    int miss = 1;

    while (idx >= 0) {
      dfs(idx, nums, seen);

      while (seen[miss]) {
        miss++;
      }

      result[idx] = miss;
      idx = parents[idx];
    }

    return result;
  }
};
