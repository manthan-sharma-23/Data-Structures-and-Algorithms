#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string findValidPair(string s) {
    int n = s.length();

    unordered_map<int, int> freq;

    for (auto ch : s) {
      int num = ch - '0';
      freq[num]++;
    }

    string pair = "";

    for (int i = 1; i < n; i++) {
      if (s[i - 1] != s[i]) {

        int num1 = s[i - 1] - '0';
        int num2 = s[i] - '0';

        if (freq[num1] == num1 && freq[num2] == num2) {
          pair.push_back(s[i - 1]);
          pair.push_back(s[i]);

          return pair;
        }
      }
    }

    return pair;
  }
};