#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

// Sum(F(1) to F(k)) = F(k+2) - 1 where F(k) => kth fibonacci term
int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;
    
    // F(n) % 10 repeats after 60 elements
    // thus F(n) % 10 => F(n % 60) % 10
    const int PISANO_PERIOD_10 = 60;
    n = n % PISANO_PERIOD_10; // update n

    int first_or_prev = 0;
    int second_or_cur = 1;

    // calc F(n+2) because Sum(F(1) to F(k)) = F(k+2) - 1
    for (int i = 2; i <= n+2; ++i) {
        int calc_cur = (first_or_prev + second_or_cur)  % 10;
        first_or_prev = second_or_cur;
        second_or_cur = calc_cur;
    }

    //edge case if (F(n+2) % 10) = 0 
    if(second_or_cur == 0) {
        return 9;
    }
    return second_or_cur-1;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n) << std::endl;
}
