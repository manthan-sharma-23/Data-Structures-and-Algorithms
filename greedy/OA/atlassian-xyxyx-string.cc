#include <climits>
#include <string>

using namespace std;

// question ->
// https://docs.google.com/document/d/1WbNuAYHcN3JAY1pa3HRyTzE-647x1LrIGIyINdfM5jU/edit?tab=t.0

//  string might be XXYYYYXXXYYYYXXXXX

/*
    if there's an occurrence of 'YY' in the string
    the ans would be freq of X in the string as all the X would be surely
   converted into Z i.e +1;

    if not then the X block with lowest number of X's wont be converted to Z.
*/

int maxMagicPower(string &s) {
  int n = s.length();
  int count = 0;
  for (auto ch : s)
    if (ch == 'X')
      count++;

  if (s.find("YY") != string::npos) {
    return count;
  }

  int minX = INT_MAX, track = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'X') {
      track++;
    } else {
      minX = min(minX, track);
      track = 0;
    }
  }

  return count - minX;
}