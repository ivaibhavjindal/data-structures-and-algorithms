// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        const int size = 1e5 + 1;
        int freq[size] = {0};

        int ans = 0, count = 0;
        for (int i = 0; i < N; i++)
            freq[arr[i]] = 1;

        for (int i = 0; i < size; i++)
        {
            if (count == 0 && freq[i])
                count += freq[i];
            else if (freq[i] && freq[i - 1])
                count += freq[i];
            else
                count = freq[i];

            ans = max(ans, count);
        }

        return ans;
    }
};
