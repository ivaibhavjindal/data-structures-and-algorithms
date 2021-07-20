#include <bits/stdc++.h>
using namespace std;

/*
// S, F pair sorted in non decreasing order of F
activitySelector(A, S, F, n) {
    R = [A[1]]
    k = 1
    for i = 2 to n do  {    
        if S[i] >= F[k] 
        {
            R = R + A[i]
            k = i
        }
    }
    return A
}
*/

// O(N)
void activitySelector(vector<pair<int, int>> v, int n)
{
    // v[i].second = start time of ith activity
    // v[i].first = finish time of ith activity

    // initialisation 
    int last_activity = 0; 
    cout << "Selected activities: ";
    cout << "[" << v[last_activity].second << ", " << v[last_activity].first << "]"; // first activity always selected

    // find performable activities (O(N))
    for(int j = 1; j < n; j++) {
        // start of jth activity >= finish time of last performed activity
        if(v[j].second >= v[last_activity].first) {
            cout << ", [" << v[j].second << ", " << v[j].first << "]"; 
            last_activity = j; // update last_activity
        }
    }
}

// O(N * log(N))
void activitySelectorWithSort(vector<pair<int, int>> v, int n)
{
    sort(v.begin(), v.end()); // sort in non decreasing order of finish time
    activitySelector(v, n);
}
 
int main()
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    
    vector <pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cout << "Enter the start and end time for " << i+1 << "th activity: ";
        cin >> v[i].second >> v[i].first;
    }
    
    activitySelectorWithSort(v, n);
}
