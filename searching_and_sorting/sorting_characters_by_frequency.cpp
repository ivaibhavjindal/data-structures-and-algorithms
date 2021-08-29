// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
public:
    // custom comparator (map by values - non increasing)
    static bool comp(pair<char, int> a, pair<char, int> b)
    {
        return a.second > b.second;
    }

    string frequencySort(string s)
    {
        // freq map
        map<char, int> mp;
        for (auto x : s)
            mp[x]++;

        // vector of freq map for sorting
        vector<pair<char, int>> freq;
        for (auto p : mp)
            freq.push_back(p);

        // non increasing freq sort
        sort(freq.begin(), freq.end(), comp);

        // final string
        string ans;
        for (auto p : freq)
            while (p.second-- > 0)
                ans += p.first;

        return ans;
    }
};