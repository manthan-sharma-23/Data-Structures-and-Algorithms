#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxBanana(vector<int> v)
    {
        int mazx = INT_MIN;
        for (int n : v)
        {
            mazx = max(mazx, n);
        }
        return mazx;
    }
    int calculateTotalHours(vector<int> &v, int hourly)
    {
        int totalH = 0;
        int n = v.size();
        // find total hours:
        for (int i = 0; i < n; i++)
        {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {

        int max_pile = maxBanana(piles);

        int low = 1, high = max_pile;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int th = calculateTotalHours(piles, mid);

            if (th <= h)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};