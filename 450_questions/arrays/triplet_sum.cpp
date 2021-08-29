// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

class Solution
{
public:
    //Function to find if there exists a triplet in the
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A + n);

        for (int i = 0; i < n - 2; i++)
        {
            int search = X - A[i];
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (A[j] + A[k] == search)
                    return true;
                else if (A[j] + A[k] > search)
                    k--;
                else
                    j++;
            }
        }

        return false;
    }
};
