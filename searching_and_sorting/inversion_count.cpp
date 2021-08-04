// https://www.hackerrank.com/challenges/ctci-merge-sort/problem

long merge(vector<int> &arr, int s, int e)
{
    long cross_count = 0;
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;

    vector<int> temp;
    while (i <= m && j <= e)
    {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);

        else
        {
            // all the elements in left array to
            // right of element inserted will add to inversions
            cross_count = (m - i + 1);
            temp.push_back(arr[j++]);
        }
    }

    while (i <= m)
        temp.push_back(arr[i++]);

    while (j <= e)
        temp.push_back(arr[j++]);

    int k = 0;
    for (int idx = s; idx <= e; idx++)
        arr[idx] = temp[k++];

    return cross_count;
}

long inversions(vector<int> arr, int s, int e)
{
    if (s >= e)
        return 0;

    int mid = (s + e) / 2;
    long left_inversions = inversions(arr, s, mid);
    long right_inversions = inversions(arr, mid + 1, e);
    long cross_inversions = merge(arr, s, e);

    return left_inversions + right_inversions + cross_inversions;
}

long countInversions(vector<int> arr)
{
    return inversions(arr, 0, arr.size() - 1);
}