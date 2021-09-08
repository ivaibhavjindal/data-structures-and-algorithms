// https://leetcode.com/problems/buddy-strings/

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        if (s == goal)
        {
            map<char, int> mp;
            for (auto ch : s)
            {
                mp[ch]++;
                if (mp[ch] > 1)
                    return true;
            }

            return false;
        }
        else
        {
            int n = s.size();
            vector<int> mismatch;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != goal[i])
                    mismatch.push_back(i);
            }

            if (mismatch.size() != 2)
                return false;

            if (s[mismatch[0]] == goal[mismatch[1]] && s[mismatch[1]] == goal[mismatch[0]])
                return true;

            return false;
        }
    }
};