#include <bits/stdc++.h>
#include <math.h>

using namespace std;

bool possiblePluck(vector<int> arr, int day, int m, int k)
{
    int n = arr.size();
    int count = 0, noOfB = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            count++;
        }
        else
        {
            noOfB += (count / k);
            count = 0;
        }
    }
    noOfB += (count / k);
    return noOfB >= m;
}

int gardenBruteForce(vector<int> arr, int m, int k)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size();

    if (val > n)
        return -1;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int n : arr)
    {
        mini = min(mini, n);
        maxi = max(maxi, n);
    }

    for (int i = mini; i <= maxi; i++)
        if (possiblePluck(arr, i, m, k))
            return i;

    return -1;
}

int gardenOptimal(vector<int> arr, int m, int k)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size();

    if (val > n)
        return -1;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int n : arr)
    {
        mini = min(mini, n);
        maxi = max(maxi, n);
    }

    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (possiblePluck(arr, mid, m, k))
        {
            high = high - 1;
        }
        else
        {
            low = low + 1;
        }
    }

    return low;
}

int main()
{
    return 0;
}