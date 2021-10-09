#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void twoEqualSumSubsets(ll n) 
{
    ll sum_of_first_n = (n * (n+1)) / 2;

    // cannot divide odd sum equally
    if(sum_of_first_n & 1)
        cout << "NO\n"; 
    else {
        ll half_sum = sum_of_first_n / 2;
        vector <int> first_half, second_half;
        for(int i = n; i >= 1; i--) {
            if(i <= half_sum) {
                first_half.push_back(i);
                half_sum -= i;
            }
            else
                second_half.push_back(i);
        }
        
        cout << "YES\n";
        cout << first_half.size() << endl;
        for(auto x: first_half)
            cout << x << " ";
        cout << "\n" << second_half.size() << endl;
        for(auto x: second_half)
            cout << x << " ";
    }
}

int main() 
{
    ll n;
    cin >> n;
    twoEqualSumSubsets(n);
}