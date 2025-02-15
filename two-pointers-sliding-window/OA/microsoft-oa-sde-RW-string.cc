
// link ->
// https://www.desiqna.in/16582/microsoft-sde-oa-coding-questions-set-119

#include <iostream>
#include <string>

using namespace std;

int findReplacements(string &a, string &b) {
  int n1 = a.length(), n2 = b.length();

  if (n1 != n2)
    return -1;

  int steps = 0;

  for (int i = 0; i < n1; i++) {
    if (a[i] == b[i]) {
      if (a[i] == '?') {
        continue;
      } else {
        return -1;
      }
    }

    if (b[i] == '?') {
      steps++;
      if (a[i] == 'R') {
        b[i] = 'W';
      } else if (a[i] == 'W') {
        b[i] = 'R';
      }
    }
    if (a[i] == '?') {
      steps++;
      if (b[i] == 'R') {
        a[i] = 'W';
      } else if (b[i] == 'W') {
        a[i] = 'R';
      }
    }
  }

  int score1 = 0, score2 = 0, space = 0;
  for (int i = 0; i < n1; i++) {
    if (a[i] == '?' && b[i] == '?')
      space++;

    if (a[i] == 'R') {
      score1++;
    } else if (a[i] == 'W') {
      score1--;
    }

    if (b[i] == 'R') {
      score2++;
    } else if (b[i] == 'W') {
      score2--;
    }
  }

  score1 = abs(score1);
  score2 = abs(score2);

  cout << space << endl;

  if (abs(score1 - score2) < space)
    return -1;

  return score1 + score2 + steps;
}

int main() {
  string a, b;
  cout << "Enter string 1 : ";
  cin >> a;

  cout << "Enter string 2 : ";
  cin >> b;

  if (a.length() != b.length()) {
    cout << "Strings are of unequal length !" << endl;
  } else {
    cout << "Steps : " << findReplacements(a, b) << endl;
  }
}