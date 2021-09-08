// https://leetcode.com/problems/maximum-number-of-balloons/

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        map<char, int> mp;
        string s = "balloon";
        for (auto ch : s)
            mp[ch] = 0;

        for (auto ch : text)
            mp[ch]++;

        mp['l'] /= 2;
        mp['o'] /= 2;

        int ans = INT_MAX;
        for (auto ch : s)
            ans = min(ans, mp[ch]);

        return ans;
    }
};