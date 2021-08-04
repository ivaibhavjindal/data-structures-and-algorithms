// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
public:
    void genPatterns(vector<string> &res, string output, vector<string> mp, string digits, int n, int i)
    {
        if (i == n)
        {
            if (output.size())
                res.push_back(output);
        }
        else
        {
            for (auto x : mp[digits[i] - '2'])
                genPatterns(res, output + char(x), mp, digits, n, i + 1);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string out;
        genPatterns(ans, out, mp, digits, digits.size(), 0);
        return ans;
    }
};