#include <iostream>
#include <string>

using namespace std;

// Composing the largest number out of the given
// set of numbers (can be any number of digits)

// O(n ^ 2) Approach (Modified - Bubble Sort)

// Print the max possible number from given sorted set of integers
// by joining each number of sorted array in decreasing order
void print_largest_number_from_sorted_array(int array_length, string sorted_array[])
{
  for (int array_item_index = array_length - 1; array_item_index >= 0; array_item_index--)
    cout << sorted_array[array_item_index];

  cout << endl;
}

// Check which string forms bigger num by joining them and comparing their int values
bool is_greater_than_next_num(string num, string next_num)
{
  // string join and Convert to Int (num = "35", next_num = "42")
  int num_nextnum = stoi(num + next_num); //  => "35" + "42" => 3542
  int nextnum_num = stoi(next_num + num); // => "42" + "35" => 4235
  if (num_nextnum > nextnum_num)          // Integer comparision
    return true;
  else
    return false;
}

// Modified bubble sort to sort the array and then print max possible number
void largest_number(int array_length, string numbers_array[])
{
  for (int outer_loop_index = 0; outer_loop_index < array_length - 1; outer_loop_index++)
  {
    for (int inner_loop_index = outer_loop_index + 1; inner_loop_index < array_length; inner_loop_index++)
    {
      // bool to check if string current_outer_num forms a bigger number than string current_inner_num
      if (is_greater_than_next_num(numbers_array[outer_loop_index], numbers_array[inner_loop_index]))
      {
        // swap their places if true
        string temp = numbers_array[outer_loop_index];
        numbers_array[outer_loop_index] = numbers_array[inner_loop_index];
        numbers_array[inner_loop_index] = temp;
      }
    }
  }

  print_largest_number_from_sorted_array(array_length, numbers_array);
}

int main()
{
  int total_integers;
  cin >> total_integers;
  string integer_array[total_integers];
  for (int integer_array_index = 0; integer_array_index < total_integers; integer_array_index++)
  {
    cin >> integer_array[integer_array_index];
  }

  largest_number(total_integers, integer_array);

  return 0;
}
