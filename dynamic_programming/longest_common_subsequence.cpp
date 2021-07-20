#include <bits/stdc++.h>
using namespace std;

// O(m+n)
void printLCS(char **path, string s, int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (path[i][j] == 'D')
    {
        printLCS(path, s, i - 1, j - 1);
        cout << s[i];
    }
    else if (path[i][j] == 'U')
        printLCS(path, s, i - 1, j);
    else
        printLCS(path, s, i, j - 1);
}

// O(m*n)
int longestCommonSubsequence(string s1, string s2)
{
    s1 = '\0' + s1;
    s2 = '\0' + s2;

    int m = s1.size() - 1;
    int n = s2.size() - 1;

    int dp[m + 1][n + 1];
    char **path = new char *[m + 1];
    for (int i = 0; i <= m; i++)
        path[i] = new char[n + 1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                path[i][j] = 'D';
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = 'U';
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                path[i][j] = 'H';
            }
        }
    }

    cout << "Longest common subsequence of " << s1 << " and " << s2 << ": ";
    printLCS(path, s1, m, n);

    return dp[m][n];
}

int main()
{
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;

    int len_lcs = longestCommonSubsequence(s1, s2);
    cout << "\nLength of lcs: " << len_lcs << endl;
}