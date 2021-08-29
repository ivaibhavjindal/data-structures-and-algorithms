// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

int firstOcc(int arr[], int n, int key)
{
    int left = 0, right = n - 1, first = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < key)
            left = mid + 1;
        else if (arr[mid] > key)
            right = mid - 1;
        else
        {
            first = mid;
            right = mid - 1;
        }
    }

    return first;
}

int lastOcc(int arr[], int n, int key)
{
    int left = 0, right = n - 1, last = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < key)
            left = mid + 1;
        else if (arr[mid] > key)
            right = mid - 1;
        else
        {
            last = mid;
            left = mid + 1;
        }
    }

    return last;
}

vector<int> find(int arr[], int n, int x)
{
    vector<int> ans;
    ans.push_back(firstOcc(arr, n, x));
    ans.push_back(lastOcc(arr, n, x));

    return ans;
}