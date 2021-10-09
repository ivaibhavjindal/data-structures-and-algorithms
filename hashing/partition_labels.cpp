// https://leetcode.com/problems/partition-labels/

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();
        map<char, pair<int, int>> mp;

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            if (mp.find(ch) == mp.end())
                mp[ch].first = mp[ch].second = i;
            else
                mp[ch].second = i;
        }

        vector<pair<int, int>> vmp;
        for (auto p : mp)
            vmp.push_back(p.second);

        sort(vmp.begin(), vmp.end());

        vector<int> ans;
        int lindex = -1, rindex = -1;
        for (auto p : vmp)
        {
            if (lindex == -1 && rindex == -1)
            {
                lindex = p.first;
                rindex = p.second;
            }
            else if (p.first < rindex)
            {
                rindex = max(rindex, p.second);
            }
            else
            {
                ans.push_back(rindex - lindex + 1);
                lindex = p.first;
                rindex = p.second;
            }
        }

        ans.push_back(rindex - lindex + 1);

        return ans;
    }
};