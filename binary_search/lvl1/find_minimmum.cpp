#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[low] < nums[high])
            return min(nums[low], ans);

        if (nums[mid] <= nums[high])
        {
            ans = min(nums[mid], ans);
            high = mid - 1;
        }
        else
        {
            ans = min(nums[low], ans);
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> v = {3, 1, 2};
    cout << findMin(v) << endl;
    return 0;
}