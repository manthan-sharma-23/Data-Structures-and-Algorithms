#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    stack<int> st;
    vector<int> arr(n, 0);

    int ptr = n - 2;

    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--) {

      while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
        st.pop();
      }

      if (st.empty()) {
        arr[i] = 0;
      } else {
        arr[i] = st.top() - i;
      }

      st.push(i);
    }

    return arr;
  }
};