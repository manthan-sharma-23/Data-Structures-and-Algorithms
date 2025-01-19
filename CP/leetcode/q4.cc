#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
  int m, n;
  int largest_sum = 0;
  vector<vector<int>> allCombinations;

  int sum1D(vector<int> &nums) {
    int sum = 0;
    vector<pair<int, int>> coords;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        coords.push_back(getRowAndCol(m, n, i));
      }
    }

    for (int i = 0; i < coords.size(); i++) {
      for (int j = i + 1; j < coords.size(); j++) {
        int distance = abs(coords[i].first - coords[j].first) +
                       abs(coords[i].second - coords[j].second);
        sum += distance;
      }
    }

    return sum;
  }

  void dfs(vector<int> &nums, int idx, int k, int N) {
    if (k == 0) {
      allCombinations.push_back(nums);
      return;
    }

    if (idx == N)
      return;

    for (int i = idx; i < N; i++) {
      nums[i] = 1;
      dfs(nums, idx + 1, k - 1, N);
      nums[i] = 0;
    }
  }

  pair<int, int> getRowAndCol(int m, int n, int oneDIdx) {
    int row = oneDIdx / n;
    int col = oneDIdx % n;

    return {row, col};
  }

  int distanceSum(int m, int n, int k) {
    this->m = m, this->n = n;
    int N = m * n;
    vector<int> nums(N, 0);

    dfs(nums, 0, k, N);

    for (auto combinations : allCombinations) {
      largest_sum += sum1D(combinations);
    }

    return largest_sum;
  }
};