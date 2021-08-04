// https://leetcode.com/problems/sqrtx/

class Solution
{
public:
    int mySqrt(int x)
    {
        long long s = 0, e = x, ans = 0;
        long long m;
        while (s <= e)
        {
            m = (s + e) / 2;
            if (m * m == x)
                return m;
            else if (m * m > x)
                e = m - 1;
            else
            {
                ans = m;
                s = m + 1;
            }
        }

        return (int)ans;
    }
};