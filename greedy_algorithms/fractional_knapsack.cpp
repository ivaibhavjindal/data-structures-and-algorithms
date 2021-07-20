#include <bits/stdc++.h>
using namespace std;

/*
// W, P pair sorted in decreasing order of Pi/Wi
knapSack(W, P, n, c) 
{
    max_profit = 0
    for i = 1 to n do {
        if(c > 0) {
            if c >=  W[i] 
                max_profit = P[i]
            else
                max_profit = P[i] * (c/W[i])
  
            c = c - W[i]
        } else break
    }
    return max_profit
}
*/

// O(N)
double knapSack(vector<pair<int, pair<int, int>>> v, int n, int capacity)
{
    // initialisation
    double max_profit = 0; // O(1)

    // updating max_profit O(N)
    for (int i = 0; i < n; i++)
    {
        if (capacity > 0)
        {
            // for ith item
            double profit = v[i].second.first;
            double weight = v[i].second.second;
            double unit_profit = v[i].first;

            if (capacity >= weight)
                max_profit += profit;
            else
                max_profit += capacity * unit_profit;

            capacity -= weight; // update left capacity
        }
        else
            break;
    }

    return max_profit;
}

// O(N * log(N))
double knapSackWithSort(double w[], double p[], int n, int capacity)
{
    vector<pair<int, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].first = p[i] / w[i];
        v[i].second.first = p[i];
        v[i].second.second = w[i];
    }
    sort(v.rbegin(), v.rend()); // sort in non increasing order of p[i]/w[i]

    for (int i = 0; i < n; i++)
        cout << v[i].first << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << v[i].second.first << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << v[i].second.second << " ";
    cout << endl;

    return knapSack(v, n, capacity);
}

int main()
{
    int n, c;
    cout << "Enter number of items: ";
    cin >> n;
    double w[n], p[n];
    cout << "Enter weight of each item: ";
    for (int i = 0; i < n; i++)
        cin >> w[i];
    cout << "Enter profit of each item: ";
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << "Enter capacity of knapsack: ";
    cin >> c;
    cout << "Maximum profit: " << knapSackWithSort(w, p, n, c);
}
