#include <vector>
using namespace std;

class Solution {
public:
  typedef long long ll;
  ll sumSegment(vector<int> &nums, int start, int end) {
    ll sum = 0;
    if (start < 0 || end >= nums.size())
      return 0;

    for (int i = start; i < end; i++) {
      sum += nums[i];
    }

    return sum;
  }

  vector<long long> maximumSegmentSum(vector<int> &nums,
                                      vector<int> &removeQueries) {

    vector<ll> result;
    int n = nums.size();

    for (auto query : removeQueries) {

      ll seg1 = sumSegment(nums, 0, query);
      ll seg2 = sumSegment(nums, query + 1, n);

      nums[query] = 0;
      result.push_back(max(seg1, seg2));
    }

    return result;
  }
};