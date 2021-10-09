// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int len = 0, start = 0, ans = INT_MAX, cur_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cur_sum += arr[i];

            while (cur_sum > x)
            {
                len = i - start + 1;
                ans = min(ans, len);
                cur_sum -= arr[start];
                start++;
            }
        }

        return ans;
    }
};