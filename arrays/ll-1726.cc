#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int tupleSameProduct(vector<int> &nums) {
    unordered_map<int, int> freq;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        int prod = nums[i] * nums[j];
        freq[prod]++;
      }
    }

    int count = 0;

    for (auto [n, fr] : freq) {
      count += (fr * (fr - 1) / 2);
    }

    return count;
  }
};