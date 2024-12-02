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
