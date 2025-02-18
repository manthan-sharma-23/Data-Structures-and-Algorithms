#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    long long ans = 0;

    int n = s.length();

    {
      long long shortCount = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
          ans += shortCount * (shortCount + 1LL) / 2;
          shortCount = 0;
        } else {
          shortCount++;
        }
      }
      ans += shortCount * (shortCount + 1LL) / 2;
    }

    vector<int> zeros;

    for (int i = 0; i < n; i++) {
      auto ch = s[i];
      if (ch == '0')
        zeros.push_back(i);
    }

    int totalZeros = zeros.size();

    for (int c0 = 1; c0 <= max(totalZeros, 200); c0++) {
      int minLength = c0 * 3;

      for (int start = 0; start <= zeros.size() - c0; start++) {
        int leftZero = zeros[start];
        int rightZero = zeros[start + c0 - 1];

        int lowerLeft = start > 0 ? zeros[start - 1] + 1 : 0;
        int upperLeft = leftZero;

        int lowerRight = rightZero;
        int upperRight =
            start + c0 < totalZeros ? zeros[start + c0] - 1 : n - 1;

        for (int idx = lowerLeft; idx <= upperLeft; idx++) {
          int Rmin = max(rightZero, idx + minLength - 1);
          if (Rmin <= upperRight) {
            ans += (upperRight - Rmin + 1);
          }
        }
      }
    }

    return ans;
  }
};