#include <iostream>

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

// Sum(F(f) to F(t)) => Sum(F(1) to F(t)) - Sum(F(1) to F(f-1)) 
// because both F(f) and F(t) are inclusive
int get_fibonacci_partial_sum_fast(long long f, long long t) {
    
    //(if f > 0) then calc(F(f-1)) else F(f) = F(0) = 0
    if (f > 0) {
        f--;
    }
    
    int F_from = fibonacci_sum_fast(f); // last digit of Sum((F(1) to F(f-1)))
    int F_to = fibonacci_sum_fast(t); // last digit of Sum((F(1) to F(t)))
    
    // to avoid negative answer (edge case)
    if (F_to < F_from) 
        return ((F_to + 10) - F_from);
    else
        return F_to - F_from;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
