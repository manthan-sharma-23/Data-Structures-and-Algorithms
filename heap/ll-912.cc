#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class MinHeap {
private:
  vector<int> arr;
  int sz = 0;

public:
  void push(int x) {
    arr.push_back(x);
    sz++;

    if (sz == 1)
      return;

    int i = sz - 1;

    while (i > 0 && arr[i] < arr[(i - 1) / 2]) {
      swap(arr[i], arr[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }

  void pop() {
    if (sz == 0)
      return;

    swap(arr[0], arr[sz - 1]);
    arr.pop_back();
    sz--;

    if (sz < 2)
      return;

    int i = 0;

    while (true) {
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      int smallest = i;

      if (left < sz && arr[left] < arr[smallest])
        smallest = left;
      if (right < sz && arr[right] < arr[smallest])
        smallest = right;

      if (smallest == i)
        break;

      swap(arr[i], arr[smallest]);
      i = smallest;
    }
  }

  int top() {
    if (sz == 0)
      return NAN;
    return arr[0];
  }

  int size() { return sz; }
};

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    MinHeap heap;

    for (auto num : nums)
      heap.push(num);

    vector<int> res;
    while (heap.size()) {
      res.push_back(heap.top());
      heap.pop();
    }

    return res;
  }
};