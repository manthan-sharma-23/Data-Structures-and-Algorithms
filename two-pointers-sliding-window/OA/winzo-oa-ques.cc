
//  link ->
//  https://docs.google.com/document/d/1rNsvOfgNl8SPZNZFpI1ZLpQmJqhPcaluNvDfievFs1U/edit?tab=t.0

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

//  different code
// code for finding sum fo all subarrays with each subarray having at most sum
// as k .

vector<int> pref;
int low, high;

int p(int sum, vector<int> &arr) {
  int n = arr.size();
  int count = 0, i = 0, s = 0;

  for (int j = 0; j < n; j++) {
    s += arr[j];

    while (s > sum) {
      s -= arr[i];
      i++;
    }

    count += j - i + 1;
  }

  return count;
}

int f(vector<int> arr, int maxSum) {
  int n = arr.size();

  int tsum = 0, ans = 0, sum = 0;
  int i = 0;
  for (int j = 0; j < n; j++) {
    sum += arr[j];
    int len = j - i + 1;

    tsum += len * arr[j];

    while (tsum > maxSum) {
      sum -= arr[i];
      tsum -= pref[j] - (i > 0 ? pref[i - 1] : 0);
      i++;
    }
    if (i <= j)
      ans += tsum;
    else {
      tsum = 0, sum = 0;
      i = j--;
    }
  }

  return ans;
};

int findSum(vector<int> &arr, int G) {
  int t;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    int arraysWithSumAtMostMid = p(mid, arr);

    if (arraysWithSumAtMostMid < G) {
      low = mid + 1;
    } else {
      int sumOfSubarraysWithAtMostMid = f(arr, mid);

      t = sumOfSubarraysWithAtMostMid - mid * (arraysWithSumAtMostMid - G);

      high = mid - 1;
    }
  }

  return t;
}

vector<int> specialSum(vector<int> &arr, vector<vector<int>> &queries) {
  pref.resize(arr.size());

  for (auto i = 0; i < arr.size(); i++) {
    pref[i] = pref[i - 1] + arr[i];
  }

  low = *min_element(arr.begin(), arr.end());
  high = accumulate(arr.begin(), arr.end(), 0);

  vector<int> ans;
  for (auto query : queries) {
    int left = query[0] > 0 ? 0 : query[0] - 1;
    int right = query[1];

    ans.push_back(findSum(arr, right) - findSum(arr, left));
  }

  return ans;
}
