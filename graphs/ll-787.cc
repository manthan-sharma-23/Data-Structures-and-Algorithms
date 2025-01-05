#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {

    typedef pair<int, pair<int, int>> flight_info;

    vector<vector<pair<int, int>>> adj(n);
    vector<int> minimumPrice(n, INT_MAX);
    queue<flight_info> q;

    for (int i = 0; i < flights.size(); i++) {
      adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }

    minimumPrice[src] = 0;
    q.push({k, {src, 0}});

    while (!q.empty()) {
      flight_info node = q.front();
      int stops_left = node.first;
      int from = node.second.first;
      int price = node.second.second;

      q.pop();

      if (minimumPrice[from] == INT_MAX || stops_left < 0)
        continue;

      for (auto it : adj[from]) {
        int to = it.first;
        int n_price = it.second;

        int totalPrice = price + n_price;

        if (totalPrice < minimumPrice[to] && stops_left >= 0) {
          minimumPrice[to] = totalPrice;
          q.push({stops_left - 1, {to, totalPrice}});
        }
      }
    }

    return minimumPrice[dst] == INT_MAX ? -1 : minimumPrice[dst];
  }
};