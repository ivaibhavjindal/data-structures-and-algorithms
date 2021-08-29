
// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

class Solution
{
public:
    bool checkPar(char open, char close)
    {
        if (open == '(' && close == ')')
            return true;
        if (open == '{' && close == '}')
            return true;
        if (open == '[' && close == ']')
            return true;

        return false;
    }

    bool isOpening(char brace)
    {
        return (brace == '{' || brace == '[' || brace == '(');
    }

    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        for (char c : x)
        {
            if (isOpening(c))
                st.push(c);
            else
            {
                if (st.empty() || !checkPar(st.top(), c))
                    return false;
                else
                    st.pop();
            }
        }

        return st.empty();
    }
};
