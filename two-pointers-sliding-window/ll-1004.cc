#include <vector>

using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();

    vector<pair<int, int>> prefix;

    int zeros = nums[0] == 0, ones = nums[0] == 1, prev = nums[0] == 1;
    for (int i = 1; i < n; i++) {
      int num = nums[i];

      if (num == 1) {
        if (prev == 1) {
          ones++;
        } else {
          prefix.push_back({zeros, 0});
          ones = 1;
          zeros = 0;
        }
      } else {
        if (prev == 0) {
          zeros++;
          ones = 0;
        } else {
          prefix.push_back({ones, 1});
          zeros = 1;
          ones = 0;
        }
      }
    }

    int maxOnes = 0;

    for (int i = prefix[0].second; i < prefix.size(); i += 2) {
      int zerosLeft = i - 1 >= 0 ? prefix[i - 1].first : 0;
      int zerosRight = i + 1 < n ? prefix[i + 1].first : 0;

      int newOnes = min(zerosLeft + zerosRight, k);

      maxOnes = max(prefix[i].first + newOnes, maxOnes);
    }

    return maxOnes;
  }
};