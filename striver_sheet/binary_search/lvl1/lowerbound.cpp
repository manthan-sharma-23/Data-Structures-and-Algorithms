#include <bits/stdc++.h>

using namespace std;

int lowerBoundBruteForce(vector<int> arr, int x)
{
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= x)
        {
            return i;
        }
    }

    return -1;
}

int lowerBoundOptimal(vector<int> v, int x)
{
    int n = sizeof(v);
    int low = 0, high = n - 1;
    int result = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (v[mid] >= x)
        {
            result = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return result;
}

int main(void)
{
    vector<int> v = {1, 2, 3, 4, 6, 7};

    int x = 5;

    int index = lowerBoundOptimal(v, x);

    cout << v[index] << endl;

    return 0;
}