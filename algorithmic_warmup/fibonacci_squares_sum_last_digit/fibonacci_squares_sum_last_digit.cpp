#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
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

// Sum(Square(F(1)) to Square(F(k))) = Area of Reactangle
// with length = F(k) and height = F(k) + F(k-1) i.e. F(k) * (F(k) + F(k-1)) 
int fibonacci_sum_squares_fast(long long n) {
    int f_n_last_dig = get_fibonacci_last_digit_fast(n); // get last digit of F(n)
    
    // Only if n is postive F(n-1) exists else F(n-1) = F(0) = 0
    if (n > 0) {
        n--;
    }

    int f_n_minus_1_last_dig = get_fibonacci_last_digit_fast(n); // get last digit of F(n-1)
    
    // last digit of F(n) * (F(n) + F(n-1))
    return (f_n_last_dig * ( f_n_last_dig + f_n_minus_1_last_dig)) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n) << std::endl;
}
