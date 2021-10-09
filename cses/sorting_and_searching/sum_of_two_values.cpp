#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int binarySearch(vector<pair<int, int>> &arr, int low, int high, int key) {
    if(low > high)
        return -1;

    int mid = high - (high-low)/2;
    
    if(arr[mid].first == key)
        return mid;
    else if(key > arr[mid].first)
        return binarySearch(arr, mid+1, high, key);
    else
        return binarySearch(arr, low, mid-1, key);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector <pair<int, int>> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    // sort for binary search
    sort(arr.begin(), arr.end());

    int i;
    for(i = 0; i < n; i++) {
        int k = binarySearch(arr, 0, n-1, x-arr[i].first);
        if((k != -1) && (k != i)) {
            cout << arr[i].second+1 << " " << arr[k].second+1 << endl;
            break;
        }
    }
    if(i == n)
        cout << "IMPOSSIBLE\n";
    
}
