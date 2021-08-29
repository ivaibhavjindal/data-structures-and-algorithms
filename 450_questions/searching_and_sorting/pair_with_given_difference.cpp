// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

bool findPair(int arr[], int size, int n)
{
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]] = true;

    for (int i = 0; i < n; i++)
        if (mp.find(abs(arr[i] - size)) != mp.end())
            return true;

    return false;
}