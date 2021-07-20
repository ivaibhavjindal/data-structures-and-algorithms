// https://leetcode.com/problems/is-subsequence/

class Solution
{
public:
    // check if s is subset of t => O(m+n)
    bool isSubsequence(string s, string t)
    {
        int m = t.length() - 1;
        int n = s.length() - 1;
        int i = m, j = n;

        while (i >= 0 and j >= 0)
        {
            if (t[i] == s[j])
            {
                j--;
                i--;
            }
            else
                i--;
        }

        return j == -1;
    }
};
