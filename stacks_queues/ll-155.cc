#include <vector>

using namespace std;

class MinStack {
public:
  vector<int> st;

  MinStack() { st = vector<int>(); }

  void push(int val) { st.push_back(val); }

  void pop() { st.pop_back(); }

  int top() { return st.back(); }

  int getMin() {
    int min = 1e9;

    for (auto num : st) {
      min = min > num ? num : min;
    }

    return min;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */