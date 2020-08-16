#include <iostream>
#include <algorithm>

using namespace std;

// O(n * log(n)) approach
// first sort each array individually in O(n * log(n)) time and
// then iterative over to calculate max dot product of both in
// O(n) time => Total = O(n) + 2(O(n * log(n))) = O(n * log(n))
long long max_dot_product(int length, int a[], int b[])
{
  // length = number of ads (same for a and b)
  sort(a, a + length); // sort first array (profit_per_click)
  sort(b, b + length); // sort second array (avg num clicks per day)

  long long result = 0; // total revenue

  // now since both are sorted it is same as we
  // are giving the max clicked slot to the ad that gets
  // us highest profit per click so we directly take their product
  // and add to our total revenue (result)
  for (int i = 0; i < length; i++)
  {
    result += ((long long)a[i]) * b[i];
  }
  return result; // calculated total revenue after correct distribution
}

int main()
{
  int number_of_ads;
  cin >> number_of_ads;
  int profit_per_click[number_of_ads], avg_num_clicks_per_day[number_of_ads];
  for (int i = 0; i < number_of_ads; i++)
  {
    cin >> profit_per_click[i];
  }
  for (int i = 0; i < number_of_ads; i++)
  {
    cin >> avg_num_clicks_per_day[i];
  }
  // max ad revenue that can be generated
  cout << max_dot_product(number_of_ads, profit_per_click, avg_num_clicks_per_day) << endl;
}
