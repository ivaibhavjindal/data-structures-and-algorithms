#include <iostream>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// calculate F(n) % m where F(n) => nth fibonacci term
// using the fact that it repeats after period P (called PISANO PERIOD)
// and always starts with 0, 1
// F(n) % m => F(n % P) % m 
int get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long first_or_prev = 0;
    long long second_or_cur = 1;
    long long period = 0;
    
    // cout << first_or_prev << " " <<  second_or_cur << " ";
    
    // calculate period P
    for (long long i = 2; i <= n; ++i) {
        long long temp = second_or_cur;
        second_or_cur = (second_or_cur + first_or_prev) % m;
        first_or_prev = temp;
    
        // cout << second_or_cur << " ";
    
        if ((i >= 3) && (second_or_cur == 1) && (first_or_prev == 0)) { // always starts with 0, 1
            period = i-1;
            break;        
        }
    }
    
    // cout << endl << period << endl;
    
    // period = 0 i.e. Didn't repeat till F(n) % m 
    // Then return F(n) % m as answer
    if (!period) {
        return second_or_cur;
    }

    // Else F(n) => F(term) where term = n % P (period)
    long long term = n % period;

    // edge case if (n%P = 0) => F(0) % m => 0
    if (!term) { 
        return 0;
    }

    // else calculate F(term) % m and return
    first_or_prev = 0;
    second_or_cur = 1;
    for(long long i = 2; i <= term; i++) {
        long long temp = second_or_cur;
        second_or_cur = (first_or_prev + second_or_cur) % m;
        first_or_prev = temp;
    }
    return second_or_cur;
}

int main() {    
    long long n, m;
    cin >> n >> m; // to calculate F(n) % m where F(n) => nth fibonacci term
    cout << get_fibonacci_huge_fast(n, m) << '\n';
}
