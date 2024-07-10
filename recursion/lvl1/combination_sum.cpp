#include <bits/stdc++.h>

using namespace std;

void find(vector<vector<int>> &v, vector<int> &c, vector<int> &path, int index, int target)
{
    if (index == c.size())
    {
        if (target == 0)
        {
            cout << target << endl;
            v.push_back(path);
        }
        return;
    }

    if (c[index] <= target)
    {
        path.push_back(c[index]);
        find(v, c, path, index, target - c[index]);
        path.pop_back();
    }

    find(v, c, path, index + 1, target - c[index]);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> v;
    int index = 0;
    vector<int> paths;
    find(v, candidates, paths, index, target);

    return v;
}

void print2d(vector<vector<int>> v)
{
    for (vector<int> a : v)
    {
        for (int b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> v = {2, 3, 5};
    vector<vector<int>> a = combinationSum(v, 8);
    print2d(a);
    return 0;
}