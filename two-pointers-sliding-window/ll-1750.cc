#include <deque>
#include <string>

using namespace std;

class Solution {
public:
  int minimumLength(string s) {
    int n = s.length();
    deque<pair<char, int>> a;

    for (int i = 0; i < n; i++) {
      if (!a.empty() && s[i] == a.back().first) {
        a.back().second++;
      } else {
        a.push_back({s[i], 1});
      }
    }

    while (a.size() > 1 && a.front().first == a.back().first) {
      a.pop_back();
      a.pop_front();
    }

    if (a.size() == 1) {
      auto node = a.front();

      return node.second % 2 ;
    }

    int len = 0;
    for (auto &node : a) {
      len += node.second;
    }
    return len;
  }
};
