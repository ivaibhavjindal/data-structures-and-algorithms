// https://www.geeksforgeeks.org/sparse-search/

#include <iostream>
#include <vector>
using namespace std;

int sparseSearch(vector<string> &v, int l, int r, string key)
{
    if (l > r)
        return -1;

    int mid = (l + r) / 2;
    // update mid if pointing at empty string
    if (v[mid] == "")
    {
        int i = mid - 1, j = mid + 1;
        while (true)
        {
            if (i < l && j > r)
                return -1;
            else if (i >= l && v[i] != "")
            {
                mid = i;
                break;
            }
            else if (j <= r && v[j] != "")
            {
                mid = j;
                break;
            }
            i--;
            j++;
        }
    }

    if (v[mid] > key)
        return sparseSearch(v, l, mid - 1, key);
    else if (v[mid] < key)
        return sparseSearch(v, mid + 1, r, key);
    else
        return mid;
}

int main()
{
    vector<string> v = {"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", "e"};
    cout << sparseSearch(v, 0, v.size() - 1, "bat") << endl;
}