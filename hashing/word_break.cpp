// https://leetcode.com/problems/word-break/

class Solution
{
public:
    int minBarsHelper(string s, int index, vector<string> &wordDict, set<string> &dict, vector<int> &dp)
    {
        int n = s.size();
        if (index == n)
            return 0;

        if (dp[index] != 0)
            return dp[index];

        int ans = INT_MAX;
        string cur_string = "";
        for (int j = index; j < n; j++)
        {
            cur_string += s[j];

            if (dict.find(cur_string) != dict.end())
            {
                int cur_ans = minBarsHelper(s, j + 1, wordDict, dict, dp);
                if (cur_ans != -1)
                    ans = min(ans, cur_ans + 1);
            }
        }

        if (ans == INT_MAX)
            return dp[index] = -1;

        return dp[index] = ans;
    }

    int minBars(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size(), 0);
        set<string> dict;
        for (auto word : wordDict)
            dict.insert(word);

        return minBarsHelper(s, 0, wordDict, dict, dp);
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        // cout << minBars(s, wordDict);
        return minBars(s, wordDict) != -1;
    }
};