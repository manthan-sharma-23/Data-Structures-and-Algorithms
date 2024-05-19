#include <bits/stdc++.h>

using namespace std;

bool possibleToCarry(vector<int> arr, int w, int days)
{
    int dayPass = 0;
    int wSum = 0;

    for (int n : arr)
    {

        if (wSum + n >= w)
        {
            dayPass++;
            wSum = n;
        }
        else
        {
            wSum += n;
        }
    }

    return dayPass <= days;
}

// weights are in sorted fashion
int shipWithinDaysBruteForce(vector<int> &weights, int days)
{
    int MaxSum = weights[0];
    for (int n : weights)
    {
        MaxSum += n;
    }

    int low = weights[weights.size() - 1], high = MaxSum;

    for (int i = low; i <= high; low++)
    {
        if (possibleToCarry(weights, i, days))
            return i;
    }

    return -1;
}

// Optimal Soln
int shipWithinDaysOptimal(vector<int> &weights, int days)
{
    int MaxSum = weights[0];
    for (int n : weights)
    {
        MaxSum += n;
    }

    int low = weights[weights.size() - 1], high = MaxSum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (possibleToCarry(weights, mid, days))
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

int main()
{
    return 0;
}