// https://leetcode.com/problems/simplify-path/

class Solution
{
public:
    string simplifyPath(string path)
    {
        // stringstream object
        stringstream ss(path);

        char delim = '/';
        string token;
        vector<string> tokens;

        // tokenisation
        while (getline(ss, token, delim))
        {
            // ignore ./ or multiple /
            if (token == "" || token == ".")
                continue;
            else
                tokens.push_back(token);
        }

        // handle ..
        vector<string> st;
        for (auto x : tokens)
        {
            if (x == "..")
            {
                // if not empty move to parent directory
                if (st.size())
                    st.pop_back();
            }
            else
                // push child directory
                st.push_back(x);
        }

        // join tokens
        int n = st.size();
        string ans = "/";
        for (int i = 0; i < n; i++)
        {
            ans += st[i];
            if (i != n - 1)
                ans += '/';
        }

        return ans;
    }
};