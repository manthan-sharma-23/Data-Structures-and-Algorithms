#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
class BFSolution {
public:
  int takeOrNot(vector<int> &nums, int idx, int k,
                unordered_map<int, int> &freq) {

    if (idx == nums.size())
      return 1;

    int taken{0};
    if (!freq[nums[idx] - k] && !freq[nums[idx] + k]) {
      freq[nums[idx]]++;
      taken = takeOrNot(nums, idx + 1, k, freq);
      freq[nums[idx]]--;
    }

    int not_taken = takeOrNot(nums, idx + 1, k, freq);

    return taken + not_taken;
  }

  int beautifulSubsets(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    auto ans = takeOrNot(nums, 0, k, freq);
    return ans - 1;
  }
};

class DPSolution {
  int beautifulSubsets(vector<int> &nums, int k) {
    unordered_map<int, vector<int>> freq;

    for (auto el : nums) {
      freq[el % k].push_back(el);
    }

    int ans = 1;

    for (auto &[mod_val, v] : freq) {
      sort(v.begin(), v.end());
      map<int, int> mp;

      for (auto el : v)
        mp[el]++;

      int prev_el = INT_MIN, prevNotTaken = 1, prevTaken = 0, nowNotTaken = 0,
          nowTaken = 0;

      for (auto &[el, freq] : mp) {
        int possible_subsets = pow(2, freq) - 1;

        nowNotTaken = prevNotTaken + prevTaken;
        if (prev_el + k == el) {
          nowTaken = prevNotTaken * possible_subsets;
        } else {
          nowTaken = (prevTaken + prevNotTaken) * possible_subsets;
        }

        prev_el = el;
        prevNotTaken = nowNotTaken;
        prevTaken = nowTaken;
      }
      ans *= (nowNotTaken + nowTaken);
    }
    return ans - 1;
  }
};
