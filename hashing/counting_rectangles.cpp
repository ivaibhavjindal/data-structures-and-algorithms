// https://www.codechef.com/problems/RECTCNT

#include <bits/stdc++.h>
using namespace std;

int rectangles(vector<vector<int>> &points, int n)
{
    int ans = 0;
    set<vector<int>> st;

    for (auto p : points)
        st.insert(p);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int p1x = points[i][0], p1y = points[i][1];
            int p3x = points[j][0], p3y = points[j][1];

            if ((p1x != p3x) && (p1y != p3y))
            {

                vector<int> p2 = {p3x, p1y};
                vector<int> p4 = {p1x, p3y};

                if ((st.find(p2) != st.end()) && (st.find(p4) != st.end()))
                    ans++;
            }
        }
    }

    return ans / 2;
}

int main()
{
    while (true)
    {
        int n, x, y;
        cin >> n;
        if (n == 0)
            break;
        vector<vector<int>> points;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            points.push_back({});
            points[i].push_back(x);
            points[i].push_back(y);
        }

        cout << rectangles(points, n) << endl;
    }
}