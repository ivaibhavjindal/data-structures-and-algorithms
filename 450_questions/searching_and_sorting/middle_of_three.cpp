// https://practice.geeksforgeeks.org/problems/middle-of-three2926/1

class Solution
{
public:
    int middle(int A, int B, int C)
    {
        int arr[] = {A, B, C};
        sort(arr, arr + 3);

        return arr[1];
    }
};