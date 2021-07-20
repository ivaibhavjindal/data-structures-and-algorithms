// https://leetcode.com/problems/longest-mountain-in-array/

class Solution
{
public:
    // O(N)
    int longestMountain(vector<int> &arr)
    {
        int max_len = 0, n = arr.size();
        for (int i = 1; i < n - 1; i++)
        {
            // peak
            if ((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1]))
            {
                int cur_len = 1; // peak

                // left
                int j = i;
                while (j > 0 && arr[j] > arr[j - 1])
                {
                    j--;
                    cur_len++;
                }

                // right
                j = i;
                while ((j < n - 1) && (arr[j] > arr[j + 1]))
                {
                    j++;
                    cur_len++;
                }

                max_len = max(cur_len, max_len);
            }
        }

        return max_len;
    }
};