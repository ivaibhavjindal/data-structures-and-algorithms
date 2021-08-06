// https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/

#include <iostream>
#include <queue>
#include <map>
using namespace std;

void nonRepeatingLetter(string s)
{
    map<char, int> mp;
    queue<char> q;
    for (auto x : s)
    {
        mp[x]++;
        if (mp[x] == 1)
            q.push(x);

        while (mp[q.front()] > 1)
            q.pop();

        if (q.empty())
            cout << "-1";
        else
            cout << q.front();
    }
    cout << endl;
}

int main()
{
    string s = "aaabbcdbbaac";
    nonRepeatingLetter(s);
}