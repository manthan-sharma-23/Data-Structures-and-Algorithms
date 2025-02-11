

#include <string>

using namespace std;

class Solution {
public:
  string removeOccurrences(string s, string part) {
    int l = part.length();
    string t = s;

    while (t.find(part) != string::npos) {
      int i = t.find(part);
      t = t.substr(0, i) + t.substr(i + l);
    }

    return t;
  }
};