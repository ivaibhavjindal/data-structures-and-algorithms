#include <bits/stdc++.h>
using namespace std;

// O(n)
void printParenthesis(int **bracket, int i, int j, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }

    cout << "(";
    printParenthesis(bracket, i, bracket[i][j], name);
    printParenthesis(bracket, bracket[i][j] + 1, j, name);
    cout << ")";
}

// O(n^3)
int matrixChainOrder(vector<int> p)
{
    int n = p.size();
    int m[n][n];
    int **s = new int *[n];
    for (int i = 0; i < n; i++)
        s[i] = new int[n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    cout << "Optimal Multiplication order: ";
    printParenthesis(s, 1, n - 1, name);

    return m[1][n - 1];
}

int main()
{
    int n;
    cout << "Enter matrix order size: ";
    cin >> n;
    cout << "Enter matrices dimensions: ";
    vector<int> p(n);
    for (auto &x : p)
        cin >> x;
    int scalar_mult = matrixChainOrder(p);
    cout << "\nNumber of scalar multiplications: " << scalar_mult << endl;
}