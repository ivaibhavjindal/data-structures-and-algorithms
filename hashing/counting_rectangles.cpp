// https://leetcode.com/problems/minimum-area-rectangle/

class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        long long ans = LONG_LONG_MAX;
        int n = points.size();
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
                    {
                        ans = min(ans, abs((long long)(p3x - p1x) * (p3y - p1y)));
                    }
                }
            }
        }

        if (ans == LONG_LONG_MAX)
            return 0;

        return ans;
    }
};