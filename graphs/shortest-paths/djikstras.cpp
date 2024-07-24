#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    // Define a priority queue with (current_price, current_node, stops_left)
    typedef tuple<int, int, int> flight_info;

    // Create adjacency list
    vector<vector<pair<int, int>>> adj(n);
    for (const auto &flight : flights) {
      adj[flight[0]].emplace_back(flight[1], flight[2]);
    }

    // Priority queue to store (cost, current_city, stops_left)
    priority_queue<flight_info, vector<flight_info>, greater<>> pq;
    pq.emplace(0, src,
               k + 1); // Start with k+1 stops to include the first city itself

    // Vector to track the minimum cost to reach each city with a certain number
    // of stops remaining
    vector<vector<int>> minCost(n, vector<int>(k + 2, INT_MAX));
    minCost[src][k + 1] = 0;

    while (!pq.empty()) {
      auto [price, city, stops_left] = pq.top();
      pq.pop();

      // If we reach the destination, return the price
      if (city == dst) {
        return price;
      }

      // If we still have stops left, explore neighbors
      if (stops_left > 0) {
        for (const auto &neighbor : adj[city]) {
          int next_city = neighbor.first;
          int next_price = neighbor.second;
          int new_price = price + next_price;

          // Only push to the queue if the cost is less than the recorded cost
          // with the same stops remaining
          if (new_price < minCost[next_city][stops_left - 1]) {
            minCost[next_city][stops_left - 1] = new_price;
            pq.emplace(new_price, next_city, stops_left - 1);
          }
        }
      }
    }

    // If we cannot reach the destination within k stops, return -1
    return -1;
  }
};

// Example usage:
int main() {
  Solution sol;
  vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int n = 3, src = 0, dst = 2, k = 1;
  int result = sol.findCheapestPrice(n, flights, src, dst, k);
  cout << "The cheapest price is: " << result << endl;
  return 0;
}
