#include <algorithm>
#include <cstdlib>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
    int n = nums.size();

    auto vec = nums;
    sort(vec.begin(), vec.end());

    unordered_map<int, list<int>> mp;
    unordered_map<int, int> numToGroup;
    int groupNum = 0;

    numToGroup[vec[0]] = groupNum;
    mp[groupNum].push_back(vec[0]);
    for (int i = 1; i < n; i++) {
      if (abs(vec[i] - vec[i - 1]) > limit) {
        groupNum++;
      }

      numToGroup[vec[i]] = groupNum;
      mp[groupNum].push_back(vec[i]);
    }

    vector<int> res(n);

    for (int i = 0; i < n; i++) {
      int num = nums[i];
      int group = numToGroup[num];

      res[i] = *mp[group].begin();
      mp[group].pop_front();
    }

    return res;
  }
};