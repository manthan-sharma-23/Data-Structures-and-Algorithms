#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool maxSubstringLength(string s, int k) {
    int n = s.size();
    if (k == 0)
      return true;

    vector<int> left(26, n), right(26, -1);

    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a';
      left[c] = min(left[c], i);
      right[c] = max(right[c], i);
    }

    vector<pair<int, int>> specialStrings;

    for (int start = 0; start < n; start++) {
      if (start != left[s[start] - 'a'])
        continue;
      int end = right[s[start] - 'a'];
      int j = start;
      bool valid = true;

      while (j <= end) {
        if (left[s[j] - 'a'] < start) {
          valid = false;
          break;
        }
        end = max(end, right[s[j] - 'a']);
        j++;
      }

      bool isEntireString = (start == 0 && end == n - 1);

      if (valid && !isEntireString)
        specialStrings.push_back({start, end});
    }

    sort(specialStrings.begin(), specialStrings.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.second < b.second;
         });

    int nonOverlappingCount = 0;
    int lastEnd = -1;

    for (const auto &interval : specialStrings) {
      bool isNonOverlapping = (interval.first > lastEnd);

      if (isNonOverlapping) {
        nonOverlappingCount++;
        lastEnd = interval.second;
      }

      if (nonOverlappingCount >= k)
        return true;
    }

    return nonOverlappingCount >= k;
  }
};