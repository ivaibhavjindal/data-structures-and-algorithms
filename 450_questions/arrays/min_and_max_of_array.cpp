// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include <limits.h>

struct pair
{
    int min;
    int max;
};

pair min_max_array(int arr[], int n)
{
    pair ans = {INT_MAX, INT_MIN};
    for (int i = 0; i < n; i++)
    {
        ans.min = std::min(ans.min, arr[i]);
        ans.max = std::max(ans.max, arr[i]);
    }

    return ans;
}
