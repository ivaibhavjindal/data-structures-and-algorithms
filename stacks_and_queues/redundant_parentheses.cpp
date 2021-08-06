// https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/

#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char x)
{
    return ((x == '+') || (x == '*') || (x == '-') || (x == '/'));
}

// only () type brackets
bool hasRedundantParentheses(string s)
{
    stack<char> st;
    for (auto x : s)
    {
        if (x != ')')
            st.push(x);
        else
        {
            bool hasOp = false;
            while (!st.empty() && st.top() != '(')
            {
                if (isOperator(st.top()))
                    hasOp = true;
                st.pop();
            }

            if (st.top() == '(')
                st.pop();

            if (!hasOp)
                return true;
        }
    }

    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << hasRedundantParentheses(s) << endl;
}