#include <iostream>

// minimum number of coins needed to change the input value
// (an integer) into coins with denominations 1, 5, and 10
int get_change(int amount)
{
  int left_amount = amount;
  int ten_denomintaion_coins = amount / 10;
  left_amount = amount % 10; // between 0 and 9
  int five_denomination_coins = left_amount / 5;
  left_amount = left_amount % 5;            // between 0 and 4
  int one_denomination_coins = left_amount; // because left_amount / 1 = left_amount
  int total_coins = ten_denomintaion_coins + five_denomination_coins + one_denomination_coins;
  return total_coins;
}

int main()
{
  int amount;
  std::cin >> amount;
  std::cout << get_change(amount) << '\n';
}
