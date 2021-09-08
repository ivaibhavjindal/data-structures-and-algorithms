// https://www.hackerrank.com/challenges/count-triplets-1/problem

long countTriplets(vector<long> arr, long r)
{
    unordered_map<long, long> left, right;
    long ans = 0;
    int n = arr.size();

    for (auto x : arr)
    {
        right[x]++;
        left[x] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        right[arr[i]]--;

        if (arr[i] % r == 0)
        {
            long a = arr[i] / r;
            long ar2 = arr[i] * r;

            ans += left[a] * right[ar2];
        }

        left[arr[i]]++;
    }

    return ans;
}
