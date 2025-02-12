#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

//  1  1 1 10 10
//  2  5 6 20 12

/*
    mp= {
        1 -> {2, 5, 6}
        10 -> {20, 12}
    }

    mp={
        1->{6},
        2->{2,5},
        10 -> {20, 12}
    }

    mp = {
        1->{6},
        2-> {5},
        3 -> {2},
        10 -> {20},
        11 -> {12}
    }
*/

int minCost(vector<int> &nums, vector<int> &costs) {
  int n = nums.size();
  map<int, multiset<int>> mp;
  map<int, int> sums;

  for (int i = 0; i < n; i++) {
    int num = nums[i], cost = costs[i];
    mp[num].insert(cost);
    sums[num] += cost;
  }

  int cost = 0;

  auto itr = mp.begin();
  while (itr != mp.end()) {
    if (itr->second.size() > 1) {
      int sum_num = sums[itr->first];
      int maxCost = *itr->second.rbegin();
      itr->second.erase(itr->second.find(maxCost));

      cost += (sum_num - maxCost);

      int newKey = itr->first + 1;
      sums[newKey] += sum_num - maxCost;
      mp[newKey].insert(itr->second.begin(), itr->second.end());
      mp[itr->first].clear();
    }
    ++itr;
  }

  return cost;
}

int main() {
  vector<int> nums = {1, 1, 4, 10, 10};

  vector<int> costs = {2, 5, 6, 20, 12};

  cout << minCost(nums, costs) << endl;
}