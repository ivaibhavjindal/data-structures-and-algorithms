#include <iostream>
#include <vector>

using namespace std;

// Iterative approach (Does not use stack space)
long iterative_binary_search(const vector<long long> &sorted_array, long leftmost_item_index, long rightmost_item_index, long long element_to_find)
{
  while (leftmost_item_index <= rightmost_item_index)
  {
    long mid_element_index = leftmost_item_index + ((rightmost_item_index - leftmost_item_index) / 2);

    // element found at mid of array
    if (element_to_find == sorted_array[mid_element_index])
      return mid_element_index;

    // element lies in left portion
    else if (element_to_find < sorted_array[mid_element_index])
      rightmost_item_index = mid_element_index - 1;

    // element lies in right portion
    else
      leftmost_item_index = mid_element_index + 1;
  }
  // element not found
  return -1;
}

// Recursive approach
long recursive_binary_search(const vector<long long> &sorted_array, long leftmost_item_index, long rightmost_item_index, long long element_to_find)
{
  // base case (element not found and array reduced to empty array)
  if (leftmost_item_index > rightmost_item_index)
    return -1;

  size_t mid_element_index = leftmost_item_index + ((rightmost_item_index - leftmost_item_index) / 2);

  // element found at mid of array
  if (element_to_find == sorted_array[mid_element_index])
    return mid_element_index;

  // element lies in left portion
  else if (element_to_find < sorted_array[mid_element_index])
    return recursive_binary_search(sorted_array, leftmost_item_index, mid_element_index - 1, element_to_find);

  // element lies in right portion
  else
    return recursive_binary_search(sorted_array, mid_element_index + 1, rightmost_item_index, element_to_find);
}

int main()
{
  long number_of_items;
  cin >> number_of_items;

  vector<long long> items_array(number_of_items);
  for (size_t cur_item_index = 0; cur_item_index < number_of_items; cur_item_index++)
    cin >> items_array[cur_item_index];

  long number_of_keys_to_find;
  cin >> number_of_keys_to_find;

  vector<long long> keys_array(number_of_keys_to_find);
  for (size_t cur_key_index = 0; cur_key_index < number_of_keys_to_find; cur_key_index++)
    cin >> keys_array[cur_key_index];

  for (size_t cur_key_index = 0; cur_key_index < number_of_keys_to_find; ++cur_key_index)
    cout << recursive_binary_search(items_array, 0, number_of_items, keys_array[cur_key_index]) << " ";
  cout << endl;
}
