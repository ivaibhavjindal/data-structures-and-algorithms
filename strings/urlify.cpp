#include <iostream>
#include <cstring>
using namespace std;

void urlify(char *s)
{
    int spaces = 0;

    for (int i = 0; s[i]; i++)
        if (s[i] == ' ')
            spaces++;

    int idx = strlen(s) + 2 * spaces;
    s[idx] = '\0';

    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s[idx - 1] = '0';
            s[idx - 2] = '2';
            s[idx - 3] = '%';
            idx -= 3;
        }
        else
        {
            s[idx - 1] = s[i];
            idx--;
        }
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    urlify(input);
    cout << input << endl;
}