// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

class Solution
{
public:
    int bottomUp(int arr[], int n)
    {
        if (n == 1)
            return arr[0];

        vector<int> dp(n, 0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++)
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);

        return dp[n - 1];
    }

    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        return bottomUp(arr, n);
    }
};
