// https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int freq[26] = {0};
        int ans = 0;
        for (char c : allowed)
            freq[c - 'a']++;

        for (auto word : words)
        {
            ans += 1;

            for (char c : word)
            {
                if (freq[c - 'a'] == 0)
                {
                    ans -= 1;
                    break;
                }
            }
        }

        return ans;
    }
};