// https://leetcode.com/problems/longest-common-prefix/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        map<string, int> mp;
        for (auto str : strs)
        {
            string cur;
            for (auto c : str)
            {
                cur += c;
                mp[cur]++;
            }
        }

        int n = strs.size();
        string ans;
        for (auto p : mp)
            if (p.second == n && p.first.size() > ans.size())
                ans = p.first;

        return ans;
    }
};