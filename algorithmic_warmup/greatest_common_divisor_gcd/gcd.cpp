#include <iostream>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

// recursive fast algorithm
long long gcd_fast(long long a, long long b) {
  // replace a with b if (a < b) as we assume a >= b
  if(a < b) {
    a = a + b;
    b = a - b;
    a = a - b;
  }
  if (b == 0) // base case when (a % b == 0)
    return a;
  // gcd (a, b) = gcd(b, a % b)
  gcd_fast(b, a % b);
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << gcd_fast(a, b) << endl;
  return 0;
}
