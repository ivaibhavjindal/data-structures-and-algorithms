// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

string isSubset(int a1[], int a2[], int n, int m)
{
    int c = 0;
    map<int, int> mp;
    for (int i = 0; i < m; i++)
        mp[a2[i]] = 0;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(a1[i]) != mp.end() && (mp[a1[i]] == 0))
        {
            mp[a1[i]] = 1;
            c++;
        }
    }

    if (c == m)
        return "Yes";
    else
        return "No";
}