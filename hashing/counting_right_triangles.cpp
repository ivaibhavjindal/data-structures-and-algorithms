// https://www.geeksforgeeks.org/count-of-right-angled-triangle-formed-from-given-n-points-whose-base-or-perpendicular-are-parallel-to-x-or-y-axis/

#include <bits/stdc++.h>
using namespace std;

int countRightTriangles(vector<vector<int>> &points)
{
    long long ans = 0;
    unordered_map<int, int> mpx, mpy;
    for (auto p : points)
    {
        mpx[p[0]]++;
        mpy[p[1]]++;
    }

    for (auto p : points)
        ans += (long long)(mpx[p[0]] - 1) * (mpy[p[1]] - 1);

    return ans;
}

int main()
{
    int n, x, y;
    cin >> n;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++)
    {
        vector<int> point;
        cin >> x >> y;
        point.push_back(x);
        point.push_back(y);

        points.push_back(point);
    }

    cout << countRightTriangles(points) << endl;
}