#include <climits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxDifferenceOddEvenFreq(const string &s, int k) {
    int n = s.length();
    if (n < k)
      return 0;

    unordered_map<char, int> freqMap;
    int maxDiff = INT_MIN;

    for (int i = 0; i < k; ++i) {
      freqMap[s[i]]++;
    }

    auto calcMaxDiff = [&]() {
      int oddFreq = 0, evenFreq = 0;
      for (auto &entry : freqMap) {
        if (entry.second % 2 != 0) {
          oddFreq += entry.second;
        } else {
          evenFreq += entry.second;
        }
      }
      return oddFreq - evenFreq;
    };

    maxDiff = max(maxDiff, calcMaxDiff());

    for (int i = k; i < n; ++i) {
      char outgoing = s[i - k];
      freqMap[outgoing]--;
      if (freqMap[outgoing] == 0) {
        freqMap.erase(outgoing);
      }

      char incoming = s[i];
      freqMap[incoming]++;

      maxDiff = max(maxDiff, calcMaxDiff());
    }

    return maxDiff;
  }

  int maxDifference(string s, int k) {
    int n = s.length();

    int maxDiff = 0;

    for (int i = k; i < n; i++) {
      maxDiff = max(maxDiff, maxDifferenceOddEvenFreq(s, i));
    }

    return maxDiff;
  }
};