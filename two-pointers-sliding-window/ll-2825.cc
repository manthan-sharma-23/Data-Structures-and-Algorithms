#include <string>

using namespace std;
class Solution {
public:
  char otherCharacter(char c) {
    if (c == 'a')
      return 'z';
    else
      return c - 1;
  }

  bool canMakeSubsequence(string str1, string str2) {

    int i = 0, j = 0;

    while (i < str1.length() && j < str2.length()) {
      if (str1[i] == str2[j] || otherCharacter(str1[i]) == str2[j])
        j++;
      i++;
    }

    return j == str2.length();
  }
};