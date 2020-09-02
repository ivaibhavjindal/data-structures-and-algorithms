#include <iostream>

using namespace std;

// Iterate from beginning and insert item at correct position
void insertion_sort(int arr[], int len)
{
    // sorting items one by one from left
    for (int i = 1; i < len; i++)
    {
        int cur_value = arr[i],
            cur_index = i;
        // pushing array positon to right till we find correct place to insert cur value
        while ((cur_index > 0) && (arr[cur_index - 1] > cur_value))
        {
            arr[cur_index] = arr[cur_index - 1];
            cur_index = cur_index - 1;
        }
        arr[cur_index] = cur_value;
    }
}

void print_array(int arr[], int len)
{
    for (int cur_item_index = 0; cur_item_index < len; cur_item_index++)
        cout << arr[cur_item_index] << " ";
    cout << endl;
}

int main()
{
    int array_len;
    cin >> array_len;

    // Input numbers into array
    int arr[array_len];
    for (int i = 0; i < array_len; i++)
        cin >> arr[i];

    // sort array
    insertion_sort(arr, array_len);

    // print sorted array
    print_array(arr, array_len);
    return 0;
}
