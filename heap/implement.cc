#include <cmath>
#include <iostream>
#include <utility>
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

  void print() {
    for (int i = 0; i < sz; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  int size() { return sz; }
};

class MaxHeap {
private:
  int sz = 0;
  vector<int> arr;

public:
  void push(int x) {
    arr.push_back(x);
    sz++;

    if (sz == 1)
      return;

    int i = sz - 1;
    while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
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
      int largest = i;

      if (right < sz && arr[largest] < arr[right])
        largest = right;
      if (left < sz && arr[largest] < arr[left])
        largest = left;

      if (largest == i)
        break;

      swap(arr[i], arr[largest]);
      i = largest;
    }
  }

  int top() {
    if (sz == 0)
      return NAN;
    return arr[0];
  }

  void print() {
    for (int i = 0; i < sz; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  int size() { return sz; }
};

int main() {
  MaxHeap maxH;
  MinHeap minH;
  maxH.push(2);
  maxH.push(3);
  maxH.push(4);
  maxH.push(4);
  maxH.push(4);

  cout << "MAX HEAP" << endl;

  cout << maxH.top() << endl;

  maxH.print();
  maxH.pop();
  maxH.pop();
  maxH.print();

  cout << "MIN HEAP" << endl;

  minH.push(2);
  minH.push(3);
  minH.push(4);
  minH.push(4);
  minH.push(4);

  cout << minH.top() << endl;

  minH.print();
  minH.pop();
  minH.pop();
  minH.print();
}