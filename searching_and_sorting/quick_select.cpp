// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution
{
public:
    // O(N)
    int partition(vector<int> &arr, int low, int high)
    {
        // initialisation
        int i = low - 1;       // O(1)
        int pivot = arr[high]; // O(1)

        // perform partition (O(N))
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i += 1;               // all elements till i <= pivot
                swap(arr[i], arr[j]); // move element <= pivot to its left
            }
        }
        swap(arr[i + 1], arr[high]); // move pivot to its correct position

        return (i + 1); // index of pivot
    }

    // quick select
    int kthSmallest(vector<int> &arr, int s, int e, int k)
    {
        int p = partition(arr, s, e);

        if (p == k)
            return arr[p];
        else if (p > k)
            return kthSmallest(arr, s, p - 1, k);
        else
            return kthSmallest(arr, p + 1, e, k);
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int kthsmall = nums.size() - k;
        return kthSmallest(nums, 0, nums.size() - 1, kthsmall);
    }
};
