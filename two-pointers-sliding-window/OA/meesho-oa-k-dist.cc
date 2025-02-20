/*
 Given a string which consists of characters from “0” to “9”; find the number of
 substrings which contain character “5” ->  “k” number of times.
*/

#include <iostream>
#include <string>

using namespace std;

int numOfSubstrings(string &s, int k) {
  int n = s.length();
  int num = 0;

  int count5 = 0;

  int i = 0;
  for (int j = 0; j < n; j++) {
    if (s[j] == '5')
      count5++;

    while (count5 > k) {
      if (s[i++] == '5')
        count5--;
    }

    if (count5 == k) {
      num += j - i + 1;
    }
  }

  return num;
}

int main() {
  string s = "00888005";
  int k = 1;

  cout << numOfSubstrings(s, k) << endl;
}