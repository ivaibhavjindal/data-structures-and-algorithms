// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

class Solution
{
public:
    void permutation(string s, int l, int h, vector<string> &ans)
    {
        if (l == h)
            ans.push_back(s);
        else
        {
            for (int i = l; i <= h; i++)
            {
                swap(s[l], s[i]);
                permutation(s, l + 1, h, ans);
                swap(s[l], s[i]);
            }
        }
    }

    vector<string> find_permutation(string S)
    {
        vector<string> ans;
        permutation(S, 0, S.size() - 1, ans);
        sort(ans.begin(), ans.end());

        return ans;
    }
};