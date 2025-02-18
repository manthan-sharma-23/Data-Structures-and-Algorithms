#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int main() {

  int n;
  cin >> n;

  int a[n];

  for (int i = 0; i < n; i++)
    cin >> a[i];

  set<int> hash;

  for (auto it : a) {
    hash.insert(it);
  }

  cout << hash.size() << endl;
}