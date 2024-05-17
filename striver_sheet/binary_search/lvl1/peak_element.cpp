#include <bits/stdc++.h>

// Find peak element in the array
using namespace std;

int findPeakIndex(vector<int> nums)
{
    int n = nums.size();
    int peak;

    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            peak = mid;

        if (nums[mid] > nums[mid + 1])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return peak;
}

int main() { return 0; }