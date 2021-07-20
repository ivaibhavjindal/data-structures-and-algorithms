#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// strings
void tokenizeSStream(string input)
{
    // stringstream object
    stringstream ss(input);

    char delim = ' ';
    string token;
    vector<string> tokens;

    while (getline(ss, token, delim))
        tokens.push_back(token);

    for (auto token : tokens)
        cout << token << endl;
}

// character arrays
void tokenizeStrTok(char *input)
{
    const char delim[1] = {' '};
    char *token = strtok(input, delim);

    while (token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL, delim);
    }
}

// same as strtok
char *customStrTok(char *str, char delim)
{
    // static pointer to string(str)
    static char *input = NULL;

    // first call (input points to start of str)
    if (str != NULL)
        input = str;

    // if end of input after tokenisation
    if (input == NULL)
        return NULL;

    // dynamic array
    static char *token = new char[strlen(input) + 1];
    int i = 0;

    // replace each delim as '\0' inside string
    for (; input[i] != '\0'; i++)
    {
        if (input[i] != delim)
            token[i] = input[i];
        else
        {
            token[i] = '\0'; // terminate token
            // point input to next token (for next function call)
            input = input + i + 1;
            return token; // return current token
        }
    }

    // out of loop
    token[i] = '\0';
    input = NULL;

    return token;
}

void tokenizeCustomStrTok(char *input)
{
    char delim = ' ';
    char *token = customStrTok(input, delim);

    while (token != NULL)
    {
        cout << token << endl;
        token = customStrTok(NULL, delim);
    }
}

int main()
{
    string inp;
    getline(cin, inp);
    tokenizeSStream(inp);

    char str[1000];
    cin.getline(str, 1000);
    tokenizeStrTok(str);

    char s[1000];
    cin.getline(s, 1000);
    tokenizeCustomStrTok(s);
}