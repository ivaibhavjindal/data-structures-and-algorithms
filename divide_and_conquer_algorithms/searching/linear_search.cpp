#include <iostream>

using namespace std;

// Recursive linear search
int recursive_linear_search(long long array[], int start_or_cur_index, int end_index, long long element_to_find)
{
    // base case (if we have iterated over whole array)
    if (end_index < start_or_cur_index)
        return -1; // element not found

    // if element found; return its index
    if (array[start_or_cur_index] == element_to_find)
        return start_or_cur_index;

    // recurse from next position
    return recursive_linear_search(array, start_or_cur_index + 1, end_index, element_to_find);
}

// Iterative linear search
int iterative_linear_search(long long array[], int start_index, int end_index, long long element_to_find)
{
    // Iterate over array and check if any element matches the element to find
    for (int cur_item_index = start_index; cur_item_index <= end_index; ++cur_item_index)
    {
        if (array[cur_item_index] == element_to_find)
            return cur_item_index;
    }
    return -1; // element not found
}

int main()
{
    int number_of_items;
    cin >> number_of_items;

    long long arr_of_items[number_of_items];
    for (int item_index = 0; item_index < number_of_items; item_index++)
        cin >> arr_of_items[item_index];

    long long key_to_search;
    cin >> key_to_search;

    int found_item_index = iterative_linear_search(arr_of_items, 0, number_of_items - 1, key_to_search);
    if (found_item_index != -1)
        cout << key_to_search << " found at index " << found_item_index << endl;
    else
        cout << key_to_search << " is not present in array" << endl;
}