// https://practice.geeksforgeeks.org/problems/find-the-median0527/1

class Solution
{
public:
    int find_median(vector<int> v)
    {
        int n = v.size();

        sort(v.begin(), v.end());

        if (n & 1)
            return v[n / 2];
        else
            return (v[n / 2 - 1] + v[n / 2]) / 2;
    }
};