// https://leetcode.com/problems/number-of-good-pairs/

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int ans = 0;
        map<int, int> mp;

        for (auto num : nums)
            mp[num]++;

        for (auto p : mp)
            ans += (p.second * (p.second - 1)) / 2;

        return ans;
    }
};
