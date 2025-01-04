#include <iostream>

using namespace std;

int main() {

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;

    cin >> n;
    cin >> s;

    int i = s.find("...");

    if (i >= 0) {
      cout << 2 << endl;
    } else {
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == '.')
          count++;
      }
      cout << count << endl;
    }
  }
}