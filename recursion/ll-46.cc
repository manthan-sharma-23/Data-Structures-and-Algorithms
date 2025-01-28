#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  int N;

  void f(vector<int> &nums, vector<bool> &used, vector<int> &path) {
    if (path.size() == N) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < N; i++) {
      if (!used[i]) {
        used[i] = true;
        path.push_back(nums[i]);
        f(nums, used, path);
        used[i] = false;
        path.pop_back();
      }
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    N = nums.size();
    vector<bool> used(N, false);
    vector<int> path;
    f(nums, used, path);
    return res;
  }
};