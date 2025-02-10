#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, bool> hash;

    for (int num : nums) {
      hash[num] = true;
    }

    int maxLen = 0;
    for (int num : nums) {
      if (hash[num - 1])
        continue;

      int t = num, len = 0;
      while (hash[t]) {
        hash.erase(t);
        t++, len++;
      }

      maxLen = max(maxLen, len);
    }

    return maxLen;
  }
};