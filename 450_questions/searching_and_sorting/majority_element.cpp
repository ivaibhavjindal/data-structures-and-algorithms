// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        map<int, int> mp;
        for (int i = 0; i < size; i++)
            mp[a[i]]++;

        for (auto p : mp)
            if ((2 * p.second) > size)
                return p.first;

        return -1;
    }
};
