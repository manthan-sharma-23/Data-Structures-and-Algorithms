#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    stack<int> st;
    int volume = 0;
    st.push(height[0]);
    for (int i = 1; i < n; i++) {
      while (!st.empty() && height[i] > height[st.top()]) {
        int top = st.top();
        st.pop();

        if (st.empty())
          break;
      }

      st.push(height[i]);
    }

    return volume;
  }
};

class O_Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();

    vector<int> prefixMax(n, 0);
    vector<int> suffixMax(n, 0);

    prefixMax[0] = height[0];
    for (int i = 1; i < n; i++) {
      prefixMax[i] = max(prefixMax[i - 1], height[i]);
    }

    suffixMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }

    int volume{0};

    for (int i = 0; i < n; i++) {
      int leftMax = prefixMax[i];
      int rightMax = suffixMax[i];

      int temp = min(leftMax, rightMax) - height[i];

      if (temp > 0) {
        volume += temp;
      }
    }

    return volume;
  }
};