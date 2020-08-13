#include <iostream>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(long long n) {
    if (n <= 1)
        return n;

    // Fibonacci Series % 10 repeats after 60 elements
    // so F(n) % 10 => F( n % 60 ) % 10;
    const int PISANO_PERIOD_10 = 60;
    n = n % PISANO_PERIOD_10;  // update n

    // edge case when completely divisible => F(0) % 10 => 0 
    if(n == 0) {
        return 0;
    }

    int first_or_prev = 0;
    int second_or_cur = 1;

    // calculate only the last dig of each fib number till n
    for (int i = 2; i <= n; ++i) {
        int calc_cur = (first_or_prev + second_or_cur)  % 10;
        first_or_prev = second_or_cur;
        second_or_cur = calc_cur;
    }

    return second_or_cur; // required last digit of fib number
}



int main() {
    int n;
    cin >> n;
    cout << get_fibonacci_last_digit_fast(n) << '\n';
}
