// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

class Solution
{
public:
    void sort012(int a[], int n)
    {
        int count[] = {0, 0, 0};
        int i = 0;

        for (; i < n; i++)
            count[a[i]]++;

        i = 0;
        for (int num = 0; num <= 2; num++)
        {
            while (count[num])
            {
                a[i] = num;
                count[num]--;
                i++;
            }
        }
    }
};