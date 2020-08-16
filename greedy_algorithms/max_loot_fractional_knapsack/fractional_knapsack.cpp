#include <iostream>

using namespace std;

// find the max value of loot a thief can get given that the items can fit
// in his knapsack assuming that any fraction of a loot item can be taken.
double get_optimal_value(int capacity, int number_of_items, int weights[], int values[])
{
  double optimal_value = 0.0;
  int cur_optimal_index = 0;
  double cur_optimal_value_per_weight = double(values[0]) / double(weights[0]);
  while (capacity > 0)
  {
    // select optimal item by calculating max value per weight(unit)
    for (int i = 0; i < number_of_items; i++)
    {
      if (weights[i] > 0 && cur_optimal_value_per_weight < (double(values[i]) / double(weights[i])))
      {
        cur_optimal_index = i;
        cur_optimal_value_per_weight = double(values[i]) / double(weights[i]);
      }
    }

    // available loot > capacity
    if (cur_optimal_value_per_weight == 0)
      break;

    // cout << "Weight Available of Current Optimal Item: " << weights[cur_optimal_index] << endl;
    // cout << "Current Optimal Index:" << cur_optimal_index << endl;
    // cout << "Current Optimal Value per Unit: " <<  cur_optimal_value_per_weight << endl;

    // update weight left of selected optimal item, capacity left, total value of loot
    int quantity_to_transfer = capacity < weights[cur_optimal_index] ? capacity : weights[cur_optimal_index];
    capacity = capacity - quantity_to_transfer;
    weights[cur_optimal_index] = weights[cur_optimal_index] - quantity_to_transfer;
    optimal_value = optimal_value + (quantity_to_transfer * cur_optimal_value_per_weight);

    // cout << "Weight of Current Optimal Item Transferred:" <<  quantity_to_transfer << endl;
    // cout << "Value Added by Current Optimal Item: " << (quantity_to_transfer * cur_optimal_value_per_weight) << endl;

    cur_optimal_value_per_weight = 0;
  }

  return optimal_value;
}

int main()
{
  int total_items;
  int capacity_of_knapsack;
  cin >> total_items >> capacity_of_knapsack;
  int values[total_items];
  int weights[total_items];
  for (int i = 0; i < total_items; i++)
  {
    cin >> values[i] >> weights[i];
  }

  double max_loot_possible = get_optimal_value(capacity_of_knapsack, total_items, weights, values);

  cout.precision(10);
  cout << max_loot_possible << endl;
  return 0;
}
