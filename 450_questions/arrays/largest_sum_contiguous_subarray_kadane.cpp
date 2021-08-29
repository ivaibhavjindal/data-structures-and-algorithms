// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

class Solution
{
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n)
    {
        int cur_max = arr[0], cur_sum = arr[0];
        for (int i = 1; i < n; i++)
        {
            cur_sum = max(arr[i], cur_sum + arr[i]);
            cur_max = max(cur_sum, cur_max);
        }

        return cur_max;
    }
};
