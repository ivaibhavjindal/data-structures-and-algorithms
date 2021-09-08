// https://leetcode.com/problems/russian-doll-envelopes/

class Solution
{
public:
    int bottomUp(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end());

        int ans = 1;
        int n = envelopes.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < i; j++)
            {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    dp[i] = max(dp[i], 1 + dp[j]);
                // else if(envelopes[j][0] == envelopes[i][0])
                //     break;
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        return bottomUp(envelopes);
    }
};