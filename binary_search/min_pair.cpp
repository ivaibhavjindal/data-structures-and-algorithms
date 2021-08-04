// https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void minDiffPair(vector<int> arr1, vector<int> arr2)
{
    // sort for binary search
    sort(arr2.begin(), arr2.end());

    int l = 0, r = 0, min_dif = INT_MAX;
    for (auto x : arr1)
    {
        // lb is index of element >= x so we check for lb and lb-1
        int lb = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
        if (lb >= 1 && abs(x - arr2[lb - 1]) < min_dif)
        {
            min_dif = abs(x - arr2[lb - 1]);
            l = x;
            r = arr2[lb - 1];
        }
        if (lb != arr2.size() and abs(x - arr2[lb]) < min_dif)
        {
            min_dif = abs(x - arr2[lb]);
            l = x;
            r = arr2[lb];
        }
    }

    cout << l << " " << r << endl;
}

int main()
{
    vector<int> num1 = {-1, 5, 10, 20, 3};
    vector<int> num2 = {26, 134, 135, 15, 17};
    minDiffPair(num1, num2);
}