// https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1

class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        map<string, int> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]]++;

        string maxfreq = "";
        int maxfr = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[arr[i]] > maxfr)
            {
                maxfr = mp[arr[i]];
                maxfreq = arr[i];
            }
        }

        maxfr = 0;
        mp[maxfreq] = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[arr[i]] > maxfr)
            {
                maxfr = mp[arr[i]];
                maxfreq = arr[i];
            }
        }

        return maxfreq;
    }
};
