#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    int n;
    cin >> n;

    for (int i = 0; i < n - 2; i++) {
      int num;
      cin >> num;
      if (num == 1)
        s.push_back('1');
      else
        s.push_back('0');
    }

    if (s.find("101") == string::npos) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}