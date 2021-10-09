#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

ll minSubsetSumDifference(int arr[], int cur_item, ll set1_sum, ll total_sum)
{
    if(cur_item == 0)
        return abs((total_sum - set1_sum) - set1_sum);

    // min sum when item is included in 1st set or when in 2nd set
    return min(minSubsetSumDifference(arr, cur_item-1, set1_sum + arr[cur_item], total_sum),
               minSubsetSumDifference(arr, cur_item-1, set1_sum, total_sum));
}

int main() 
{
    int n;
    cin >> n;
    int arr[n];
    ll total_sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        total_sum += arr[i];
    }
    cout << minSubsetSumDifference(arr, n-1, 0, total_sum) << endl;
}
