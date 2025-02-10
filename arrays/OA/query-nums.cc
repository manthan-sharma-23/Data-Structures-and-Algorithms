// Understanding -> Given an array of size N; and a target -> find the minimum
// number of operations needed to make all elements of array equal to target ->
// there are multiple target in order of Q;

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> queriesNums(int N, vector<int> query, vector<int> nums) {

  vector<int> res(query.size(), 0);

  int sumAll = accumulate(nums.begin(), nums.end(), 0);

  vector<int> prefixSum(nums.size(), 0);

  for (int i = 0; i < N; i++) {
    prefixSum[i] = prefixSum[i - 1] + nums[i];
  }

  sort(nums.begin(), nums.end());

  for (int i = 0; i < query.size(); i++) {
    int target = query[i];
    int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

    int lsum = prefixSum[idx - 1];
    int rsum = prefixSum[N - 1] - lsum;

    int opr = abs(target * N - lsum) + abs(rsum - N * target);

    res[i] = opr;
  }

  return res;
}