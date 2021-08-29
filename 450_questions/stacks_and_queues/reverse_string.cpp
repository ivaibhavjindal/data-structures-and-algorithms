// https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1

//return the address of the string
char *reverse(char *S, int len)
{
    stack<char> st;
    for (int i = 0; i < len; i++)
        st.push(S[i]);

    int i = 0;
    while (!st.empty())
    {
        S[i] = st.top();
        st.pop();
        i++;
    }

    return S;
}