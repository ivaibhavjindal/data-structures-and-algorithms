// https://leetcode.com/problems/contains-duplicate/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, bool> mp;
        for (auto x : nums)
        {
            if (mp.find(x) != mp.end())
                return true;
            mp[x] = true;
        }

        return false;
    }
};