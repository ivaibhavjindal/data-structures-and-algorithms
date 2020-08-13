#include <iostream>

using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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

// lcm * gcd = num1 * num2
long long lcm_fast(long long a, long long b) {
  return a * b / gcd_fast(a, b);
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << lcm_fast(a, b) << endl;
  return 0;
}
