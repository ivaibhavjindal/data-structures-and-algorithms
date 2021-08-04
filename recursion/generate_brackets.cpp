// https://leetcode.com/problems/generate-parentheses/

class Solution
{
public:
    void brackets(vector<string> &res, string output, int n, int open, int close, int i)
    {
        if (i == 2 * n)
            res.push_back(output);

        // place open bracket at ith position
        if (open < n)
            brackets(res, output + '(', n, open + 1, close, i + 1);

        // place closing bracket at ith position
        if (close < open)
            brackets(res, output + ')', n, open, close + 1, i + 1);
    }

    vector<string> generateParenthesis(int n)
    {
        string out;
        vector<string> ans;
        brackets(ans, out, n, 0, 0, 0);
        return ans;
    }
};
