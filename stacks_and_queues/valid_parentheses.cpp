// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isMatch(char open, char close)
    {
        return ((open == '[' && close == ']') ||
                (open == '{' && close == '}') ||
                (open == '(' && close == ')'));
    }

    bool isValid(string s)
    {
        stack<char> st;
        for (auto x : s)
        {
            if (x == '[' || x == '(' || x == '{')
                st.push(x);
            else if (st.empty() || (!isMatch(st.top(), x)))
                return false;
            else
                st.pop();
        }

        return st.empty();
    }
};