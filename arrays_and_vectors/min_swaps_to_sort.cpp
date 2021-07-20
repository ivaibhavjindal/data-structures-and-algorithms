// https://www.hackerrank.com/challenges/minimum-swaps-2/problem

int minimumSwaps(vector<int> arr)
{
    int swaps = 0;
    int n = arr.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].first = arr[i];
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        int node = i;
        if (!visited[node])
        {
            int cycle_elements = 0;

            while (!visited[node])
            {
                visited[node] = true;
                node = v[node].second;
                cycle_elements++;
            }

            swaps += cycle_elements - 1;
        }
    }

    return swaps;
}
