#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int atMostK(vector<int> &nums, int k) {
  int n = nums.size();
  unordered_map<int, int> mp;

  int i = 0;
  int count = 0;

  for (int j = 0; j < n; j++) {
    mp[nums[j]]++;

    int d = mp.size();
    while (d > k) {
      mp[nums[i]]--;
      if (mp[nums[i]] == 0)
        mp.erase(nums[i]);

      d = mp.size();
      i++;
    }

    count += (j - i + 1);
  }

  return count;
}

int medianSubarrayUniqueness(vector<int> &nums) {
  int n = nums.size();

  long long M;

  long long T = 1LL * n * (n + 1) / 2;

  if (T % 2) {
    M = (T + 1) / 2;
  } else {
    M = T / 2;
  }

  unordered_set<int> s(nums.begin(), nums.end());
  int distinctVals = s.size();

  int low = 1, high = distinctVals;

  int ans = distinctVals;

  while (low <= high) {
    int mid = (low + high) / 2;

    int cnt = atMostK(nums, mid);

    if (cnt >= M) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}