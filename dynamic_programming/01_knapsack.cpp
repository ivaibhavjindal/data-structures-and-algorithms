#include <bits/stdc++.h>
using namespace std;

// O(N * W)
int _01knapSack(int weight[], int profit[], int n, int capacity)
{
    int dp[n+1][capacity+1] = {0}, keep[n+1][capacity+1] = {0};
    for(int i = 0; i <= capacity; i++)
        dp[0][i] = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= capacity; w++) {
            if((weight[i] <= w) && ((profit[i] + dp[i-1][w-weight[i]]) > dp[i-1][w])) {
                dp[i][w] = profit[i] + dp[i-1][w-weight[i]];
                keep[i][w] = 1;
            } else {
                dp[i][w] = dp[i-1][w];
                keep[i][w] = 0;
            }
        }
    }
    
    int left_capacity = capacity;
    cout << "Items selected: ";
    for(int i = n; i > 0; i--) {
        if(keep[i][left_capacity]) {
            cout << i << " ";
            left_capacity -= weight[i];
        }
    }
    cout << "\nRemaining space in knapsack: " << left_capacity << endl;

    return dp[n][capacity];
}

int main()
{
    int n, c;
    cout << "Enter number of items: ";
    cin >> n;

    int w[n+1] = {0}, p[n+1] = {0};
    cout << "Enter weight of each item: ";
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    cout << "Enter profit of each item: ";
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    cout << "Enter capacity of knapsack: ";
    cin >> c;

    int max_profit = _01knapSack(w, p, n, c);
    cout << "Maximum profit: " << max_profit << endl;
}
