#include <algorithm>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
  unordered_map<string, vector<string>> maptickets;

public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {

    for (vector<string> t : tickets)
      maptickets[t[0]].push_back(t[1]);

    vector<string> result;
    stack<string> st;

    st.push("JFK");

    while (!st.empty()) {
      auto currNode = st.top();
      if (!maptickets[currNode].empty()) {
        string nextNode = maptickets[currNode].back();
        maptickets[currNode].pop_back();
        st.push(nextNode);
      } else {
        result.push_back(currNode);
        st.pop();
      }
    }

    reverse(result.begin(), result.end());
    return result;
  }
};