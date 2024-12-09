#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> oldv = {0,1, 2, 3, 4, 5, 6};
  std::vector<int> newv;

  int mid = oldv.size() / 2;

  newv.assign(oldv.begin() + mid, oldv.end());

  oldv.resize(mid);

  printf("Hello");
  return 0;
}
