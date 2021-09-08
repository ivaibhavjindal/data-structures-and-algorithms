// https://leetcode.com/problems/find-lucky-integer-in-an-array/

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        map<int, int> mp;

        for (auto num : arr)
            mp[num]++;

        int ans = -1;
        for (auto p : mp)
        {
            if (p.first == p.second)
                ans = max(ans, p.first);
        }

        return ans;
    }
};