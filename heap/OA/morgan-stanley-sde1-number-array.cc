//  link ->
//  https://www.desiqna.in/12816/morgan-sde1-coding-questions-and-solutions-india-april-2023

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minCost(vector<int> &nums) {
  priority_queue<int, vector<int>, greater<int>> heap;

  for (auto num : nums) {
    heap.push(num);
  }
  int cost = 0;
  while (heap.size() > 1) {
    int x = heap.top();
    heap.pop();
    int y = heap.top();
    heap.pop();

    heap.push(x + y);

    cost += x + y;
  }

  return cost;
}

int main() {
  vector<int> nums = {4, 6, 8, 2};

  cout << minCost(nums) << endl;

  return 0;
}