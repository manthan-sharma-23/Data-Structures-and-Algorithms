#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  unordered_map<int, unordered_map<int, int>> memo;

  int countSetBits(unsigned int n) {
    int count = 0;
    while (n) {
      n &= (n - 1);
      count++;
    }
    return count;
  }

  bool canTakeString(const string &s, int mask, int &newMask) {
    newMask = mask;
    for (char ch : s) {
      int ind = ch - 'a';
      if (newMask & (1 << ind))
        return false;
      newMask |= (1 << ind);
    }
    return true;
  }

  int f(const vector<string> &arr, int i, int mask) {
    if (i == arr.size()) {
      return countSetBits(mask);
    }

    if (memo[i].count(mask))
      return memo[i][mask];

    int notTake = f(arr, i + 1, mask);
    int take = INT_MIN;
    int newMask;
    if (canTakeString(arr[i], mask, newMask)) {
      take = f(arr, i + 1, newMask);
    }

    return memo[i][mask] = max(take, notTake);
  }

  int maxLength(vector<string> &arr) {
    memo.clear();
    return f(arr, 0, 0);
  }
};


