#include <iostream>
#include <cassert>

using namespace std;

// recursive and slow algorithm 
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

// calculate nth fibonacci term
int fibonacci_fast(int n) {
    int arr[n];
    arr[0] = 0; // initialse first element as 0
    arr[1] = 1; // initialse second element as 1

    // cout << arr[0] << " " << arr[1] << " ";
    
    for(int i = 2; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2]; // current element = sum of previous two elements
    
        // cout << arr[i] << " " << endl;
    }
    return arr[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    cin >> n;
    cout << fibonacci_fast(n) << '\n';
    return 0;
}
