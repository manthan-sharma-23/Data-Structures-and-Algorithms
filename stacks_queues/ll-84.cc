#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();

    stack<int> st;
    st.push(heights[0]);
    int i = 1;

    while (i < n) {
      int h = heights[i];

      if (st.top() > h) {
      }
    }
  }
};